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

#include "AEvent.hpp"

namespace ecs {

template<typename T, typename E>
using Callback = void (T::*)(E&);

class EventManager {
  private:
    class ICallbackHandler {
      public:
        virtual ~ICallbackHandler() = default;

      public:
        virtual void call(AEvent& event) = 0;
    };

    template<typename T, typename E>
    class CallbackHandler : public ICallbackHandler {
      private:
        T& _subscriber;
        Callback<T, E> _callback;

      public:
        CallbackHandler(T& subscriber, Callback<T, E> callback) : _subscriber(subscriber), _callback(callback) {};
        ~CallbackHandler() override = default;

      public:
        void call(AEvent& event) override
        {
            (_subscriber.*_callback)(dynamic_cast<E&>(event));
        }
    };

  private:
    std::map<std::type_index, std::vector<ICallbackHandler*>*> _subscribers {};

  public:
    EventManager() = default;
    ~EventManager()
    {
        this->unsubscribe();
    }

  public:
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

    void unsubscribe()
    {
        for (auto& i : _subscribers) {
            if (i.second != nullptr)
                i.second->clear();
        }
        _subscribers.clear();
    }

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
