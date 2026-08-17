#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"

int main() {
    Data miData;
    miData.id = 42;
    miData.name = "Objeto de Prueba";
    miData.nivel = 99.9f;

    std::cout << "--- ESTADO INICIAL ---" << std::endl;
    std::cout << "Dirección original de miData : " << &miData << std::endl;
    std::cout << "Contenido: ID=" << miData.id << ", Nombre=" << miData.name << "\n\n";

    uintptr_t raw_ptr = Serializer::serialize(&miData);
    
    std::cout << "--- SERIALIZACIÓN ---" << std::endl;
    std::cout << "Valor raw (uintptr_t)        : 0x" << std::hex << raw_ptr << std::dec << "\n\n";

    Data* puntero_recuperado = Serializer::deserialize(raw_ptr);

    std::cout << "--- DESERIALIZACIÓN ---" << std::endl;
    std::cout << "Dirección recuperada         : " << puntero_recuperado << std::endl;

    std::cout << "\n--- RESULTADO DE LA VERIFICACIÓN ---" << std::endl;
    if (puntero_recuperado == &miData) {
        std::cout << "[ÉXITO] ¡Los punteros coinciden!" << std::endl;
        std::cout << "Datos recuperados: ID=" << puntero_recuperado->id 
                  << ", Nombre=" << puntero_recuperado->name << std::endl;
    } else {
        std::cout << "[ERROR] Los punteros no son iguales." << std::endl;
    }

    return 0;
}
