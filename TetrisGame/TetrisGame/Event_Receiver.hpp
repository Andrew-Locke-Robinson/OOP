#ifndef EVENT_RECEIVER_HPP
#define EVENT_RECEIVER_HPP

#include <SFML/Graphics.hpp>
#include "Event_Listener.hpp"

class Event_Receiver
{
public:
	Event_Receiver(sf::RenderWindow* w) : window(w)
	{
	}
	~Event_Receiver();

	void
		listen(Event_Listener& l)
	{
		listeners.push_back(&l);
	}

	// Notify listeners of queued events.
	void
		poll()
	{
		sf::Event e;
		while (window->pollEvent(e))
			process(e);
	}

	// Notify listeners of a single event.
	void process(sf::Event const& e)
	{
		switch (e.type) {
		case sf::Event::Closed:
			return notify([e](Event_Listener* l) { l->on_close(); });

		case sf::Event::Resized:
			return notify([e](Event_Listener* l) { l->on_resize(e.size); });

		case sf::Event::MouseButtonPressed:
			return notify([e](Event_Listener* l) { l->on_mouse_button_press(e.mouseButton); });
		case sf::Event::MouseButtonReleased:
			return notify([e](Event_Listener* l) { l->on_mouse_button_release(e.mouseButton); });

		case sf::Event::KeyPressed:
			return notify([e](Event_Listener* l) { l->on_key_press(e); });
		case sf::Event::KeyReleased:
			return notify([e](Event_Listener* l) { l->on_key_press(e); });
		default:
			break;
		}
	}

	template<typename F>
	void notify(F fn)
	{
		for (Event_Listener* l : listeners)
		for (Event_Listener* l : listeners)
			fn(l);
	}

	// The window that we can poll for events.
	sf::RenderWindow* window;

	// A list of listeners to notify about particular
	// events.
	std::vector<Event_Listener*> listeners;

};

#endif