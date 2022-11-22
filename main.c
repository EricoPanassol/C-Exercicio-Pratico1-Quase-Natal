#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

int padrao;
int modoEscolha;

ISR(INT0_vect)
{

    padrao++;
    if(padrao == 6)
    {
        padrao = 1;
    }

    _delay_ms(500);
    if(!(PIND & (1 << PD2))){
        _delay_ms(2500);
    }
    
    if(!(PIND & (1 << PD2)))
    {
        if(modoEscolha == 0){
            padrao = 1;
            modoEscolha = 1;
        }else{
            if(padrao == 1)
            {
                padrao = 5;
            }else{ 
                padrao--;
                }
            PORTB = 0b00000000;
            modoEscolha = 0;
        }
    }
}

int main(void)
{
    DDRD = 0x00;                                                            // todos os pinos D como entrada
    PORTD = 0xff;                                                           // todos os pull-ups da porta D habilitados
    DDRB |= (1 << PB1) | (1 << PB2) | (1 << PB3) | (1 << PB4) | (1 << PB5); // seta PB1, PB2, PB3, PB4, PB5 como saida
    padrao = 1;  // variavel que define o padrao a ser executado
    modoEscolha = 0;                                                          
    // Configuracao da interrupcao
    EICRA = 0b00000010; // interrupcao externa INT0 na borda de descida
    EIMSK = 0b00000001; // habilita a interrupcao externa INT0
    sei();
    // DDRB |= (1 << PB0)
    // PINB & (1 << PB0) verifica se o pino está em 1
    while (1)
    {
        while (padrao == 1 && modoEscolha == 0)
        {
            PORTB |= (1 << PB5); // liga LED
            _delay_ms(100);
            PORTB &= ~(1 << PB5); // desliga LED
            _delay_ms(100);
            PORTB |= (1 << PB4); // liga LED
            _delay_ms(100);
            PORTB &= ~(1 << PB4); // desliga LED
            _delay_ms(100);
            PORTB |= (1 << PB3); // liga LED
            _delay_ms(100);
            PORTB &= ~(1 << PB3); // desliga LED
            _delay_ms(100);
            PORTB |= (1 << PB2); // liga LED
            _delay_ms(100);
            PORTB &= ~(1 << PB2); // desliga LED
            _delay_ms(100);
            PORTB |= (1 << PB1); // liga LED
            _delay_ms(100);
            PORTB &= ~(1 << PB1); // desliga LED
            _delay_ms(100);
        }
        while (padrao == 2 && modoEscolha == 0)
        {
            PORTB |= (1 << PB1);
            _delay_ms(100);
            PORTB |= (1 << PB2);
            _delay_ms(100);
            PORTB |= (1 << PB3);
            _delay_ms(100);
            PORTB |= (1 << PB4);
            _delay_ms(100);
            PORTB |= (1 << PB5);
            _delay_ms(100);
            PORTB &= ~(1 << PB1);
            _delay_ms(100);
            PORTB &= ~(1 << PB2);
            _delay_ms(100);
            PORTB &= ~(1 << PB3);
            _delay_ms(100);
            PORTB &= ~(1 << PB4);
            _delay_ms(100);
            PORTB &= ~(1 << PB5);
            _delay_ms(100);
        }

        while (padrao == 3 && modoEscolha == 0)
        {
            PORTB = 0;
            _delay_ms(300);
            PORTB = 0xff;
            _delay_ms(300);
            PORTB = 0;
            _delay_ms(300);
        }

        while (padrao == 4 && modoEscolha == 0)
        {
            for (int j = 0; j < 10; j++)
            {
                PORTB = 0x1;
                for (int i = 0; i < 8; i++)
                {
                    PORTB = PORTB << 1;
                    _delay_ms(70);
                }
                PORTB = 0x80;
                for (int i = 0; i < 10; i++)
                {
                    PORTB = PORTB >> 1;
                    _delay_ms(70);
                }
            }
        }
        while (padrao == 5 && modoEscolha == 0)
        {
            PORTB |= (1 << PB1);
            _delay_ms(150);
            PORTB &= ~(1 << PB1);
            _delay_ms(150);
            PORTB |= (1 << PB1);
            _delay_ms(150);
            PORTB &= ~(1 << PB1);
            _delay_ms(150);
            PORTB |= (1 << PB2);
            _delay_ms(150);
            PORTB &= ~(1 << PB2);
            _delay_ms(150);
            PORTB |= (1 << PB2);
            _delay_ms(150);
            PORTB &= ~(1 << PB2);
            _delay_ms(150);
            PORTB |= (1 << PB3);
            _delay_ms(150);
            PORTB &= ~(1 << PB3);
            _delay_ms(150);
            PORTB |= (1 << PB3);
            _delay_ms(150);
            PORTB &= ~(1 << PB3);
            _delay_ms(150);
            PORTB |= (1 << PB4);
            _delay_ms(150);
            PORTB &= ~(1 << PB4);
            _delay_ms(150);
            PORTB |= (1 << PB4);
            _delay_ms(150);
            PORTB &= ~(1 << PB4);
            _delay_ms(150);
            PORTB |= (1 << PB5);
            _delay_ms(150);
            PORTB &= ~(1 << PB5);
            _delay_ms(150);
            PORTB |= (1 << PB5);
            _delay_ms(150);
            PORTB &= ~(1 << PB5);
        }
        while(modoEscolha == 1){
            if(padrao == 1 && modoEscolha == 1){
                PORTB = 0b00000010;
            }
            if(padrao == 2 && modoEscolha == 1){
                PORTB = 0b00000100;
            }
            if(padrao == 3 && modoEscolha == 1){
                PORTB = 0b00001000;
            }
            if(padrao == 4 && modoEscolha == 1){
                PORTB = 0b00010000;
            }
            if(padrao == 5 && modoEscolha == 1){
                PORTB = 0b00100000;
            }
        }
    }

    
    // // 5 - Padrão que pisca duas vezes todos os leds
    // while(1){
    //     PORTB |= (1 << PB0);
    //     _delay_ms(150);
    //     PORTB &= ~(1 << PB0);
    //     _delay_ms(150);
    //     PORTB |= (1 << PB0);
    //     _delay_ms(150);
    //     PORTB &= ~(1 << PB0);
    //     _delay_ms(150);
    //     PORTB |= (1 << PB1);
    //     _delay_ms(150);
    //     PORTB &= ~(1 << PB1);
    //     _delay_ms(150);
    //     PORTB |= (1 << PB1);
    //     _delay_ms(150);
    //     PORTB &= ~(1 << PB1);
    //     _delay_ms(150);
    //     PORTB |= (1 << PB2);
    //     _delay_ms(150);
    //     PORTB &= ~(1 << PB2);
    //     _delay_ms(150);
    //     PORTB |= (1 << PB2);
    //     _delay_ms(150);
    //     PORTB &= ~(1 << PB2);
    //     _delay_ms(150);
    //     PORTB |= (1 << PB3);
    //     _delay_ms(150);
    //     PORTB &= ~(1 << PB3);
    //     _delay_ms(150);
    //     PORTB |= (1 << PB3);
    //     _delay_ms(150);
    //     PORTB &= ~(1 << PB3);
    //     _delay_ms(150);
    //     PORTB |= (1 << PB4);
    //     _delay_ms(150);
    //     PORTB &= ~(1 << PB4);
    //     _delay_ms(150);
    //     PORTB |= (1 << PB4);
    //     _delay_ms(150);
    //     PORTB &= ~(1 << PB4);
    //     _delay_ms(150);
    //     PORTB |= (1 << PB5);
    //     _delay_ms(150);
    //     PORTB &= ~(1 << PB5);
    //     _delay_ms(150);
    //     PORTB |= (1 << PB5);
    //     _delay_ms(150);
    //     PORTB &= ~(1 << PB5);
    // }

    // // 4 - Padrão que vai e volta nos LEDS
    // while (1) {
    //     for (int j = 0; j < 10; j++) {
    //         PORTB = 0x1;
    //         for (int i = 0; i < 8; i++) {
    //             PORTB = PORTB << 1;
    //             _delay_ms(70);
    //         }
    //         PORTB = 0x80;
    //         for (int i = 0; i < 10; i++) {
    //             PORTB = PORTB >> 1;
    //             _delay_ms(70);
    //         }
    //     }
    // }

    // // 3 - Padrão que pisca todos os LEDS
    // while(1){
    //     PORTB = 0;
    //     _delay_ms(300);
    //     PORTB = 0xff;
    //     _delay_ms(300);
    //     PORTB = 0;
    //     _delay_ms(300);
    // }

    // // 2- Padrão que liga um LED de cada vez
    // while(1){
    //     PORTB |= (1 << PB1);
    //     _delay_ms(100);
    //     PORTB |= (1 << PB2);
    //     _delay_ms(100);
    //     PORTB |= (1 << PB3);
    //     _delay_ms(100);
    //     PORTB |= (1 << PB4);
    //     _delay_ms(100);
    //     PORTB |= (1 << PB5);
    //     _delay_ms(100);
    //     PORTB &= ~(1 << PB1);
    //     _delay_ms(100);
    //     PORTB &= ~(1 << PB2);
    //     _delay_ms(100);
    //     PORTB &= ~(1 << PB3);
    //     _delay_ms(100);
    //     PORTB &= ~(1 << PB4);
    //     _delay_ms(100);
    //     PORTB &= ~(1 << PB5);
    //     _delay_ms(100);
    // }

    // 1 - Padrão que liga e desliga cada um dos LEDS
    // while (1)
    // {
    //     PORTB |= (1 << PB5);  // liga LED
    //     _delay_ms(50);
    //     PORTB &= ~(1 << PB5); // desliga LED
    //     _delay_ms(50);
    //     PORTB |= (1 << PB4);  // liga LED
    //     _delay_ms(50);
    //     PORTB &= ~(1 << PB4); // desliga LED
    //     _delay_ms(50);
    //     PORTB |= (1 << PB3);  // liga LED
    //     _delay_ms(50);
    //     PORTB &= ~(1 << PB3); // desliga LED
    //     _delay_ms(50);
    //     PORTB |= (1 << PB2);  // liga LED
    //     _delay_ms(50);
    //     PORTB &= ~(1 << PB2); // desliga LED
    //     _delay_ms(50);
    //     PORTB |= (1 << PB1);  // liga LED
    //     _delay_ms(50);
    //     PORTB &= ~(1 << PB1); // desliga LED
    //     _delay_ms(50);
    // }
}
