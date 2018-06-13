#include "window.h"

namespace sparx { namespace graphics {

		void window_resize(GLFWwindow *window, int width, int height);

		Window::Window(const char *title, int width, int height)
		{
			m_Title = title;
			m_Width = width;
			m_Height = height;
			if (!init())			// Error handle
				glfwTerminate();

			for (int i = 0; i < MAX_KEYS; i++)
			{
				m_Keys[i] = false;
			}
			for (int i = 0; i < MAX_BUTTONS; i++)
			{
				m_MouseButtons[i] = false;
			}
		}
		Window::~Window()
		{
			glfwTerminate();
		}
		bool Window::init()
		{
			if (!glfwInit())		// Initial init
			{
				std::cout << "Failed to initialize GLFW" << std::endl;
				return false;
			}
			
			m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, NULL, NULL);		// Returns a pointer

			if (!m_Window)
			{
				std::cout << "Failed to create GLFW window" << std::endl;
				return false;
			}

			// Initialize glfw contexts & callbacks
			glfwMakeContextCurrent(m_Window);
			glfwSetWindowUserPointer(m_Window, this);						// This ties a pointer (m_Window) to our GL window.
																			// We are not responsible for freeing any returned by OpenGL
			// (from this context, this function will be called)
			glfwSetWindowSizeCallback(m_Window, window_resize);				// Set window resize callback
			glfwSetKeyCallback(m_Window, key_callback);						// Set Key callback
			glfwSetMouseButtonCallback(m_Window, mouse_button_callback);	// Set Mouse Callback
			glfwSetCursorPosCallback(m_Window, cursor_position_callback);	// Set Cursor Pos Callback

			if (glewInit() != GLEW_OK)
			{
				std::cout << "Could not initialize GLEW" << std::endl;
				return false;
			}

			std::cout << "OpenGL " << glGetString(GL_VERSION) << std::endl;
			
			return true;
		}
		bool Window::isKeyPressed(unsigned int keycode) const
		{
			// TODO: Log this!
			if (keycode >= MAX_KEYS)
				return false;
			return m_Keys[keycode];
		}

		bool Window::isMouseButtonPressed(unsigned int button) const
		{
			// TODO: Log this!
			if (button >= MAX_BUTTONS)
				return false;
			return m_MouseButtons[button];
		}

		void Window::getMousePosition(double& x, double&y) const		// Passed by ref because we want to update the real values
		{
			x = mX;
			y = mY;
		}

		void Window::clear() const
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}
		void Window::update()
		{
			glfwPollEvents();
			glfwGetFramebufferSize(m_Window, &m_Width, &m_Height);	// sets width and height to different vals for resize

			glfwSwapBuffers(m_Window);
		}
		bool Window::closed() const
		{
			return glfwWindowShouldClose(m_Window) == 1;			// Because its a bool.....raises warning, closes window
		}

		// Not Window::methods // Recall that the WindowUserPointer is our current context and our current window
		void window_resize(GLFWwindow *window, int width, int height)
		{
			glViewport(0, 0, width, height);
		}

		void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)	// We can only access public things and friends.
		{
			Window *win = (Window*) glfwGetWindowUserPointer(window);						// GLFW's Pointer casted to and pointed at OUR WINDOW CLASS
			win->m_Keys[key] = action != GLFW_RELEASE;										// Map of the window's keypress buffer
		}
		void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
		{
			Window *win = (Window*)glfwGetWindowUserPointer(window);						// Logical
			win->m_MouseButtons[button] = action != GLFW_RELEASE;							// Map of the window's MousePress buffer
		}
		void cursor_position_callback(GLFWwindow *window, double xpos, double ypos)
		{
			Window *win = (Window*)glfwGetWindowUserPointer(window);
			win->mX = xpos;
			win->mY = ypos;

		}

	}
}