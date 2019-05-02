#ifndef EVENT_LISTENER_HPP
#define EVENT_LISTENER_HPP

#include <SFML/Graphics.hpp>

class Event_Listener
{
public:
	Event_Listener();
	~Event_Listener();

	// Window events
	virtual void on_close() { }
	virtual void on_gain_focus() { }
	virtual void on_lose_focus() { }
	virtual void on_resize(sf::Event::SizeEvent) { }

	// Mouse events
	virtual void on_mouse_button_press(sf::Event::MouseButtonEvent) { }
	virtual void on_mouse_button_release(sf::Event::MouseButtonEvent) { }

	// Keyboard events
	virtual void on_key_press(sf::Event) { }
	virtual void on_key_release(sf::Event) { }

};

#endif