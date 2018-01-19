//
// Created by Alexandre on 19/01/2018.
//

#ifndef R_TYPE_MESSAGEQUEUE_HPP
#define R_TYPE_MESSAGEQUEUE_HPP

#include <queue>

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

        void addMessage(T elem, unsigned short ownerID);

        std::pair<T, unsigned short> getMessage();

        bool isEmpty() const;

        unsigned int size() const;

    private:
        std::queue<std::pair<T, unsigned short>> _queue;
    };


    template<class T>
    MessageQueue<T>::MessageQueue()
    {}

    template<class T>
    void MessageQueue<T>::addMessage(T elem, unsigned short ownerID)
    {
        _queue.push(std::make_pair(elem, ownerID));
    }

    template<class T>
    std::pair<T, unsigned short> MessageQueue<T>::getMessage()
    {
        std::pair<T, unsigned short> tmpPair = _queue.front();
        _queue.pop();
        return tmpPair;
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
