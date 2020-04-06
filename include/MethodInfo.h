#ifndef _METHOD_INFO_HPP_
#define _METHOD_INFO_HPP_

#include <vector>
#include "Definitions.h"
#include "AttributeInfo.h"
#include "CpInfo.h"
#include <fstream>

/*!
   \brief Estrutura de um método na JVM.
 */
class MethodInfo {
    public:
        u2 accessFlags;        /*!< Flags de acesso do método */
        u2 nameIndex;          /*!< Indica onde está o nome do método na tabela constant_pool */
        u2 descriptorIndex;    /*!< Indica a posição do descritor do método na tabela constant_pool */
        u2 attributesCount;    /*!< Indica o tamanho o vetor que comporta os atributos do método */
        Attributes* attributes; /*!< Vetor de atributos */

        ~MethodInfo();
};

/*!
   \brief Vetor dos métodos da JVM.
 */
class Methods : public std::vector<MethodInfo*> {
public:
  /*!
     \brief Constrói um novo vetor de métodos.
     Assume-se que o arquivo .class está na posição do methods_count,
     mas pode ser que essa não seja uma boa ideia.
     TODO Verificar se é melhor receber o methods_count ao invés de
     lê-lo por aqui.

     \param file        Arquivo .class.
     \param fieldsCount Número de Fields.
     \param cpTable     Pool de constantes.
   */
  Methods(std::ifstream& file, u2 fieldsCount, ConstantPoolT cpTable);

  /*!
     \brief Destrói o vetor de métodos.
   */
  ~Methods();

  /*!
     \brief Imprime o vetor no terminal.
   */
  void print();

};

#endif // _METHOD_INFO_HPP_