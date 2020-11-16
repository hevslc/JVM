# JVM
Uma implementação simples de uma Máquina Virtual Java.

# Compilação
Para compilar execute o comando ```make```

# Execução
* Clonar o repositório
* Na raíz, executar o comando ```make``` para gerar o executável
* Para executar, utilize o comando ```main.exe caminho_para_o_arquivo```

# O que não pôde ser implementado
Algumas instruções não foram implementadas, entre elas, principalmente tem-se *invokespecial*, *new*, *instanceof* e *checkcast*. Isso implica que a JVM não carrega outras classes além da presente no *.class* da chamada da JVM.

Instruções que tratam de campos (estáticos ou de instância), como *putfield*, *getfield*, *putstatic*, *getstatic*, não estão completas ou não foram implementadas.

## WorkFlow
* Criar uma **nova issue** para uma situação ou escolher uma existente.
* Criar um **novo branch** para cada nova **issue**, apagar a branch quando terminar a implementação.
* Ao terminar a implementação, fazer um **pull request** para a master, delegar o *PR* para outra pessoa.

## Padrão de codificação
* Separar nomes de atributos, métodos ou classes por **caixa alta/baixa** e não por underline.

# Integrantes
* Grupo 1
* Ayllah Ahmad Lopes - 170056465
* Estevam Galvão Albuquerque - 160005663
* Hevelyn Sthefany Lima de Carvalho  - 170059031
* Kálley Wilkerson - 170038050
* Patrick Vitas Reguera Beal - 150143672
* Rodrigo Matias Xavier - 150147431

