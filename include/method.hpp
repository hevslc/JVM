#ifndef _METHODS_HPP_
#define _METHODS_HPP_

#include "definitions.h"

/*!
   \brief Estrutura de um método na JVM.
 */
class MethodInfo {
    public:
        u2 accessFlags;     /*!< Flags de acesso do método */
        u2 nameIndex;       /*!< Indica onde está o nome do método na tabela constant_pool */
        u2 descriptorIndex; /*!< Indica a posição do descritor do método na tabela constant_pool */
        u2 attributesCount; /*!< Indica o tamanho o vetor que comporta os atributos do método */
};

#endif // _METHODS_HPP_