# MINIMAL REPRODUCIBLE EXAMPLE ATTINY13A DEEP SLEEP

A partir del datasheet, he desarrollado este código para poder implementarlo a proyectos que utilicen el microcontrolador ATTINY13A. En este caso se obtienen los siguientes consumos para un programa sencillo que solo se ejecuta una sola vez en la función setup() encendiendo con una secuencia de pulsos un led:
<div align="center">
  
  |   | Con mi código  | Con librería <sleep.h> | Sin nada para dormirlo |
  | :---: | :---: | :---: | :---: |
  | **Consumo cuando <br>finaliza ejecución</br>**  | 19.4 μA  | 626 μA  | 4.68 mA  |
  | **Consumo antes función <br>*power_down_mode()*</br>**  | ≈10 mA  | ≈10 mA  | ≈10 mA  |

</div>

Como podemos observar, la primera columna es la que menos consumo tiene una vez ha entrado el microcontrolador en modo "sueño profundo". Este código se desarrolló para el proyecto [SinotimerATTINY13-chipset](https://github.com/torbol/SinotimerATTINY13-chipset).
