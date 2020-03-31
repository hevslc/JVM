#ifndef _METHOD_INFO_HPP_
#define _METHOD_INFO_HPP_

#include <vector>
#include "Definitions.h"
#include "CpInfo.h"
#include "ClassFile.h"
#include <fstream>

/*!
   \brief Flags de acesso a métodos.
   Indica a disponibilidade de acesso de um método.
 */
enum MethodAccessFlag
{
	ACC_PUBLIC       = 0x0001,  /*!< Declarado público; pode ser acessada fora de seu pacote. */
	ACC_PRIVATE      = 0x0002,  /*!< Declarado privado; acessível apenas dentro da classe em que é definido. */
	ACC_PROTECTED    = 0x0004,  /*!< Declarado protegido; pode ser acessado dentro de classes derivadas. */
	ACC_STATIC       = 0x0008,  /*!< Declarado estático. */
	ACC_FINAL        = 0x0010,  /*!< Declarado final; não pode ser sobrescrito. */
	ACC_SYNCHRONIZED = 0x0020,  /*!< Declarado synchronized; chamada é envolvida pelo uso de um monitor. */
	ACC_BRIDGE       = 0x0040,  /*!< Um método bridge, gerado pelo compilador. */
	ACC_VARARGS      = 0x0080,  /*!< Declarado com número variável de argumentos. */
	ACC_NATIVE       = 0x0100,  /*!< Declarado nativo; implementado em outra linguagem não sendo Java. */
	ACC_ABSTRACT     = 0x0400,  /*!< Declarado abstrato; nenhuma implementação é fornecida. */
	ACC_STRICT       = 0x0800,  /*!< Declarado strictfp; modo floating-point é FP-strict. */
	ACC_SYNTHETIC    = 0x1000,  /*!< Declarado sitético; não está presente no código fonte. */
};

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

/*!
   \brief Vetor dos métodos da JVM.
 */
class Methods : public std::vector<MethodInfo*> {
public:
  Methods(std::ifstream& file);
  ~Methods();
  void print();

private:
  u2 readMethodsCount(std::ifstream& file);
};

#endif // _METHOD_INFO_HPP_