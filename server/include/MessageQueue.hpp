//
// Created by Alexandre on 19/01/2018.
//

#ifndef R_TYPE_MESSAGEQUEUE_HPP
#define R_TYPE_MESSAGEQUEUE_HPP

#include <queue>
#include <iostream>

#define MAX_SIZE 50

namespace RTypeServer
{
    template<class T>
    class MessageQueue
    {
    public:
        MessageQueue();

        ~MessageQueue() = default;

        MessageQueue(const MessageQueue &) = delete;

        MessageQueue &operator=(const MessageQueue &) = delete;

        void addMessage(T elem, std::size_t ownerID);

        std::pair<T, std::size_t> getMessage();

        T &peekMessage();
        std::size_t peekOwnerID() const;

        void pop();

        bool isEmpty() const;

        unsigned int size() const;

    private:
        std::queue<std::pair<T, std::size_t>> _queue;
    };


    template<class T>
    MessageQueue<T>::MessageQueue()
    {}

    template<class T>
    void MessageQueue<T>::addMessage(T elem, std::size_t ownerID)
    {
        _queue.push(std::make_pair(elem, ownerID));
    }

    template<class T>
    std::pair<T, std::size_t> MessageQueue<T>::getMessage()
    {
        std::pair<T, std::size_t> tmpPair = _queue.front();
        _queue.pop();
        return tmpPair;
    }

    template<class T>
    T &MessageQueue<T>::peekMessage()
    {
        return _queue.front().first;
    }

    template<class T>
    std::size_t MessageQueue<T>::peekOwnerID() const
    {
        return _queue.front().second;
    }

    template<class T>
    void MessageQueue<T>::pop()
    {
        _queue.pop();
    }

    template<class T>
    bool MessageQueue<T>::isEmpty() const
    {
        return _queue.empty();
    }

    template<class T>
    unsigned int MessageQueue<T>::size() const
    {
        return _queue.size();
    }
}

#endif //R_TYPE_MESSAGEQUEUE_HPP
