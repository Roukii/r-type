//
// Created by sentrance on 10/01/18.
//

#include "AGameEngine.hpp"

namespace UgandaEngine {


    void AGameEngine::init(const std::vector<std::string> &component,
                           const std::map<std::string, std::vector<std::string>> &entity,
                           const std::map<std::string, std::function<void(RTypeProtocol::Message&)>> &action) {
        _factory = std::make_shared<Factory::FactoryEntity>(entity, action);
    }

    AGameEngine::AGameEngine() {
#ifdef __linux__
        ILib *get;
        ILib *(*external_creator)();
        void *_handle = dlopen("../build/libUGL.so", RTLD_LAZY);
        if (_handle == nullptr)
            throw std::invalid_argument("[X]Failed to dlopen.");
        external_creator = reinterpret_cast<ILib *(*)()>(dlsym(_handle, "create_lib"));
        if (external_creator == nullptr)
            throw std::invalid_argument("[X]Fail to create external_creator.");
        get = external_creator();
        std::shared_ptr<ILib> getShared(get);
        _libGraph = getShared;
        _libGraph->init();
#elif _WIN32
        ILib *(*create_graph)();
        HINSTANCE hGetProcIDDLL = LoadLibrary("..\\build\\libUGL.dll");
        if (hGetProcIDDLL != NULL)
            create_graph = reinterpret_cast<ILib *(*)()>(GetProcAddress(hGetProcIDDLL, "create_lib"));
        else
            std::cout << "Path for dll not found" << std::endl;
        ILib *get = create_graph();
        std::shared_ptr<ILib> getShared(get);
        _libGraph = getShared;
        _libGraph->init();
#endif
    }

}