/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** EventManager.hpp
*/

#ifndef OOP_INDIE_STUDIO_2019_EVENTMANAGER_HPP
#define OOP_INDIE_STUDIO_2019_EVENTMANAGER_HPP

#include <map>
#include <typeindex>

#include "Event.hpp"

/**
 * @file EventManager.hpp
 * @brief EventManager Class
 * @author Lucas.M Mattéo.F
 * @version 1.0
 * @date 03 june 2020
 */

/**
 * @namespace ecs
 */
namespace ecs {

/**
 * @def Callback
 * @tparam T : The class.
 * @tparam E : Reference on an event.
 *
 * @brief Use Callback as Method pointer which take a reference on an event.
 */
template<typename T, typename E>
using Callback = void (T::*)(E&);

/**
 * @class EventManager
 * @brief Class that manages events.
 */
class EventManager {
  private:
    /**
     * @class ICallback
     * @brief Interface of a Callback Handler.
     */
    class ICallbackHandler {
      public:
        virtual ~ICallbackHandler() = default;

      public:
        /**
         * @brief call method
         * This method call an event.
         * @param event : Event that will be called.
         */
        virtual void call(Event& event) = 0;
    };

    /**
     * @class CallbackHandler
     * @brief Wrapper of Callback functions.
     * @tparam T : Class.
     * @tparam E : Reference on an event.
     */
    template<typename T, typename E>
    class CallbackHandler : public ICallbackHandler {
      private:
        T& _subscriber; /** < Class subrscribed. */
        Callback<T, E> _callback; /** < Event that will be called. */

      public:
        /**
         * @brief Constructor
         * Constructor of CallbackHandler
         * @param subscriber : Class subrscribed.
         * @param callback : Event that will be called.
         */
        CallbackHandler(T& subscriber, Callback<T, E> callback) : _subscriber(subscriber), _callback(callback) {};
        /**
         * @brief Destructor
         * It's a default destructor because the garbage collector will take care of the rest.
         */
        ~CallbackHandler() override = default;

      public:
        /**
         * @brief call method
         * This method call an event.
         * @param event : Event that will be called.
         */
        void call(Event& event) override
        {
            (_subscriber.*_callback)(dynamic_cast<E&>(event));
        }
    };

  private:
    std::map<std::type_index, std::vector<ICallbackHandler*>*> _subscribers {}; /** < Map of subscribed.*/

  public:
    /**
     * @brief Constructor
     * Constructor of EventManager.
     */
    EventManager() = default;
    /**
     * @brief Destructor
     * Destructor that call unsubscribed method.
     */
    ~EventManager()
    {
        this->unsubscribe();
    }

  public:
    /**
     * @brief subscribe method
     * This method allows a class to subscribe one of its methods to a specific event.
     * @tparam T : The Class.
     * @tparam E : Type of the Event.
     * @param subscriber : Reference on the subscribing class.
     * @param callback : Method of the subscribing class.
     */
    template<typename T, typename E>
    void subscribe(T& subscriber, Callback<T, E> callback)
    {
        std::vector<ICallbackHandler*>* handlers = _subscribers[typeid(E)];

        if (handlers == nullptr) {
            handlers = new std::vector<ICallbackHandler*>();
            _subscribers[typeid(E)] = handlers;
        }

        handlers->push_back(new CallbackHandler<T, E>(subscriber, callback));
    }

    /**
     * @brief unsubscribe method
     * This method allows to unsubscribe all previously subscribed classes.
     */
    void unsubscribe()
    {
        for (auto& i : _subscribers) {
            if (i.second != nullptr)
                i.second->clear();
        }
        _subscribers.clear();
    }

    /**
     * @brief publish method
     * This method allows to transmit an event to all previously subscribed methods.
     * @tparam E : The event type.
     * @param event : The event to be transmitted.
     */
    template<typename E>
    void publish(E& event)
    {
        std::vector<ICallbackHandler*>* handlers = _subscribers[typeid(E)];

        if (handlers == nullptr)
            return;

        for (auto& handler : *handlers) {
            if (handler != nullptr) {
                handler->call(event);
            }
        }
    }
};

} // namespace ecs

#endif // OOP_INDIE_STUDIO_2019_EVENTMANAGER_HPP