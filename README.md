# FarmTech Solutions - Sistema de Irrigação Inteligente 🌿

Este repositório contém o desenvolvimento da **Fase 2 - Campo da Inovação** para a FIAP. O projeto consiste em um protótipo de IoT para Agricultura Digital, focado em otimizar o uso da água e monitorar a saúde do solo em tempo real.

## 🔗 Links do Projeto
* **Simulação Wokwi:** https://wokwi.com/projects/461244678231422977
* **Vídeo Demonstrativo:** https://youtu.be/jAYI65ajNvo

## 📋 Sobre o Projeto
A **FarmTech Solutions** desenvolveu uma solução automatizada para a cultura da soja. O sistema utiliza um microcontrolador para monitorar sensores e tomar decisões autônomas de irrigação, garantindo produtividade e sustentabilidade.

## 🛠️ Hardware Utilizado
* **Microcontrolador:** ESP32 DevKit V1
* **Sensor de Umidade/Temperatura:** DHT22
* **Sensor de pH:** LDR (Resistor Dependente de Luz) simulando a acidez do solo.
* **Atuador:** Relé (representando a Bomba de Irrigação).

## 🧠 Lógica de Funcionamento
O sistema opera com uma lógica de prioridade para garantir a saúde da planta em diferentes cenários. A bomba de irrigação é ativada sempre que:

1.  **Umidade Baixa:** Se a umidade detectada for inferior a **40%**.
2.  **Acidez Detectada:** Se o solo apresentar um **pH ácido (< 6.0)**, mesmo que a umidade esteja alta.

No Monitor Serial, o sistema exibe a mensagem:
`>>> IRRIGANDO (Solo Seco ou Ácido) <<<` sempre que uma dessas condições é atendida, garantindo que o agricultor saiba que a irrigação está em curso para manutenção ou correção química (fertirrigação).

## 📸 Circuito do Projeto
![Circuito FarmTech Solutions](farmtech_solutions.png)
*(Certifique-se de que a imagem no seu GitHub tenha exatamente este nome)*

## 📂 Organização do Repositório
* `/src`: Arquivo `main.ino` com o código C++ desenvolvido.
* `/assets`: Imagens do projeto e arquivo `diagram.json`.

## 🚀 Expansão Futura
O projeto foi estruturado para permitir a integração futura com algoritmos de **Inteligência Artificial**, utilizando os dados históricos de umidade e pH para prever necessidades hídricas antes mesmo do solo atingir níveis críticos.

---
**Desenvolvido por:** Guilherme Monteiro
**Curso:** Inteligência Artificial - FIAP
