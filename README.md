# Exercício Prático 1: Já é quase Natal!

Já estamos nos aproximando do final do ano e com ele chega o Natal. Comum em todas as decorações, o pisca-pisca de LEDs é um artigo natalino bastante presente nas casas.

A fim de criar um produto diferenciado, você foi chamado(a) para implementar uma solução que agrega valor ao artigo.

No presente trabalho você deve elaborar um sistema composto por **5 LEDs e um botão**.

- Sobre os LEDs devem ser aplicados **5 padrões distintos** de pisca-pisca. Os padrões devem ser definidos por você, os quais devem ser necessariamente diferentes entre si.

- Ao iniciar o sistema, um dos padrões deve ser associado aos LEDs.
- Um clique rápido no botão **(menos de 3 segundos)** faz com que um novo padrão de pisca-pisca seja ativado.
- Cada clique rápido faz mudar rapidamente para o próximo padrão.
- Caso seja realizado um clique longo no botão **(mais de 3 segundos)** então entra-se em **modo de escolha** do padrão a ser aplicado:
    - No modo de escolha, somente um dos LEDs fica ligado por vez, o que indica o padrão a ser executado.
    - O primeiro padrão está associado ao LED 1 ligado, o segundo ao LED 2 e assim sucessivamente.
    - Durante o modo de escolha, um clique curto **(menos de 3 segundos)** faz com que o próximo LED seja ligado e o anterior desligado, indicando que um próximo padrão foi escolhido.
    - Ao chegar no padrão desejado, um clique longo **(mais de 3 segundos)** indica que o padrão foi escolhido. Como resultado, sai-se do modo de escolha e aplica-se o padrão selecionado.

**Faça a entrega de uma pasta compactada (formato zip), contendo o código fonte E arquivo do simulador (.simu)**

**NÃO USE a versão 1.0.0 do simulador! Utilize a versão ESTÁVEL (0.4.15)**

# Como rodar

1. Você deve alterar o tipo de linguagem interpretada para AVR (caso esteja usando o VSCode, esta opção está no canto inferior direito da tela)

2. Na pasta raiz do projeto execute o comando `make` para compilar o código
    ```bash
    make
    ```

3. No simulador, carregue o circuito localizado na pasta `Circuit` e no `MCU` carregue o arquivo `main.hex`

Pronto. Seu Natal está garantido!