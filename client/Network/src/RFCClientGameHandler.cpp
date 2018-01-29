//
// Created by zozo on 23/01/18.
//

#include "RFCClientGameHandler.hpp"

namespace RTypeClient
{
    RFCClientGameHandler::RFCClientGameHandler(std::shared_ptr<IClientUdpSocket> &socket, std::map<int, UgandaEngine::Entity *> &ent,
                                               std::shared_ptr<UgandaEngine::AGameEngine> &eng)
            : _socket(socket), _entity(ent), _engine(eng)
    {
        initMapOfCommandHandler();
    }

    void RFCClientGameHandler::initMapOfCommandHandler()
    {
        _CommandHandler.insert({RTypeProtocol::MOV_ENTITY, &RFCClientGameHandler::RFCMoveEntity});
        _CommandHandler.insert({RTypeProtocol::DEL_ENTITY, &RFCClientGameHandler::RFCDelEntity});
        _CommandHandler.insert({RTypeProtocol::NEW_ENTITY, &RFCClientGameHandler::RFCNewEntity});
    }

    void RFCClientGameHandler::executeCommand(RTypeProtocol::Message &msg, std::size_t ownerID)
    {
        RTypeProtocol::code codeCommand = (RTypeProtocol::code) msg._msg->_header._code;
        std::cout << "code command : " << codeCommand <<  std::endl;
        if (_CommandHandler.find(codeCommand) != _CommandHandler.end())
        {
            (this->*_CommandHandler[codeCommand])(msg, ownerID);
        }
    }

    void RFCClientGameHandler::RFCMoveEntity(RTypeProtocol::Message &currentMessage, std::size_t _currentOwnerID) {
        UgandaEngine::Entity *ent = _entity[getIdFromChar(currentMessage)];
        getPosFromMessage(currentMessage, ent);
        std::cout << "Received new movement message. Pos : " << ent->_posX
                  << "|" << ent->_posY
                  << ". Id : " << getIdFromChar(currentMessage) << std::endl;
    }

    void RFCClientGameHandler::RFCDelEntity(RTypeProtocol::Message &currentMessage, std::size_t _currentOwnerID) {
        _entity.erase(_entity.find(getIdFromChar(currentMessage)));
    }

    void RFCClientGameHandler::RFCNewEntity(RTypeProtocol::Message &currentMessage, std::size_t _currentOwnerID) {
        std::cout << "new ship" << std::endl;
        _entity.insert(std::pair<int, UgandaEngine::Entity *>(getIdFromChar(currentMessage), _engine->_factory->create(static_cast<RTypeProtocol::types>(currentMessage._msg.get()->data._entity.type), _engine->_libGraph)));

        getPosFromMessage(currentMessage, _entity[getIdFromChar(currentMessage)]);
    }


    void RFCClientGameHandler::getPosFromMessage(RTypeProtocol::Message &currentMessage, UgandaEngine::Entity *ent)
    {
        union
        {
            char ch[4];
            int n;
        } char2int;



        char2int.ch[0] = currentMessage._msg.get()->data._entity._pos._x[0];
        char2int.ch[1] = currentMessage._msg.get()->data._entity._pos._x[1];
        char2int.ch[2] = currentMessage._msg.get()->data._entity._pos._x[2];
        char2int.ch[3] = currentMessage._msg.get()->data._entity._pos._x[3];

        std::cout << "CLIENT x :" << (int)char2int.ch[0] << (int)char2int.ch[1] << (int)char2int.ch[2] << (int)char2int.ch[3] << std::endl;

        ent->_speedX = char2int.n - ent->_posX;
        ent->_posX = char2int.n;

        char2int.ch[0] = currentMessage._msg.get()->data._entity._pos._y[0];
        char2int.ch[1] = currentMessage._msg.get()->data._entity._pos._y[1];
        char2int.ch[2] = currentMessage._msg.get()->data._entity._pos._y[2];
        char2int.ch[3] = currentMessage._msg.get()->data._entity._pos._y[3];

        ent->_speedY = char2int.n - ent->_posY;
        ent->_posY = char2int.n;

        std::cout << "i have pos " << ent->_posX << " " << ent->_posY;

    }

    int RFCClientGameHandler::getIdFromChar(RTypeProtocol::Message &currentMessage) {
        union
        {
            char ch[4];
            int n;
        } char2int;

        char2int.ch[0] = currentMessage._msg.get()->data._entity.id[0];
        char2int.ch[1] = currentMessage._msg.get()->data._entity.id[1];
        char2int.ch[2] = currentMessage._msg.get()->data._entity.id[2];
        char2int.ch[3] = currentMessage._msg.get()->data._entity.id[3];


        std::cout << "id :" << char2int.n << std::endl;
        return char2int.n;

    }
}