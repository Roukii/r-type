//
// Created by sentrance on 10/01/18.
//


#include <dlfcn.h>
#include "../include/AGameEngine.hpp"
#include "../../../client/Lib/include/ILib.hpp"
#include "../../../client/Lib/include/UGL.hpp"

namespace UgandaEngine {


    void AGameEngine::init(const std::vector<std::string> &component,
                           const std::map<std::string, std::vector<std::string>> &entity,
                           const std::map<std::string, std::function<void()>> &action) {
        //TODO LibGraph à implémenter


        factory = std::make_shared<Factory::FactoryEntity>(entity, action);
    }

    AGameEngine::AGameEngine() {
        ILib *get;
        ILib *(*external_creator)();
        void *_handle = dlopen("../build/libUGL.so", RTLD_LAZY);
        if (_handle == NULL)
            _handle = dlopen("../build/libUGL.dll", RTLD_LAZY);
        if (_handle == NULL)
            throw std::invalid_argument("[X]Failed to dlopen.");
        external_creator = reinterpret_cast<ILib *(*)()>(dlsym(_handle, "create_lib"));
        if (external_creator == NULL)
            throw std::invalid_argument("[X]Fail to create external_creator.");
        get = external_creator();
        std::shared_ptr<ILib> getShared(get);
        libGraph = getShared;
        libGraph->init();
    }

    AGameEngine::~AGameEngine()
    {

    }
}