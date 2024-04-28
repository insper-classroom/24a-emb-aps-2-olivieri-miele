# Controle para Shell Shockers

## Comandos:
- Joystick da esquerda: Movimentar o personagem
- Joystick central: Movimentar a tela
- Botão superior esquerdo: Atirar
- Botão superior central: Mirar
- Botão superior direito: Recarregar
- Botão inferior esquerdo: Granada
- Botão inferior central: Facada
- Botão inferior direito: Trocar de Arma
- Botão 'sozinho': pular

  ## Como ligar:
  Acione o switch para ligar o controle,feito isso ficará piscando um led até você conectar o controle por bluetooth no seu computador. Para conectá-lo, você deve executar esse comando no terminal (dentro da pasta python):
  - sudo rfcomm connect /dev/rfcomm0 98:DA:60:08:7F:CA
 
  ## O projeto está organizado da seguinte maneira:

- `hc06.h`: Arquivo de headfile com configurações do HC06, tais como pinos, uart, ..
- `hc06.c`: Arquivo `.c` com implementação das funções auxiliares para configurar o módulo bluetooth
- `main.c` Arquivo principal com os comandos do controle com inicialização do módulo bluetooth

  Diagrama de blocos:
![WhatsApp Image 2024-04-28 at 14 57 11](https://github.com/insper-classroom/24a-emb-aps-2-olivieri-miele/assets/103431278/c8902b30-f1b1-4bce-b543-e6eb5e8ffcbb)

Fotos do controle:
![WhatsApp Image 2024-04-28 at 20 04 18](https://github.com/insper-classroom/24a-emb-aps-2-olivieri-miele/assets/103431278/216664e9-ab3c-4448-86b6-7e8038c676f0)
![WhatsApp Image 2024-04-28 at 20 04 16](https://github.com/insper-classroom/24a-emb-aps-2-olivieri-miele/assets/103431278/739282eb-eb0a-4b5e-96ee-6966a5e8d407)
