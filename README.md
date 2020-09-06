### MiniMenuConsoleAplication

[GitHub Sponsors](https://github.com/SrShadowy)
[![forthebadge](https://forthebadge.com/images/badges/made-with-c-plus-plus.svg)](https://forthebadge.com)

*Um menu em c++ sem muita pespectiva.
mas funcional*

![Ilustrativo](https://i.imgur.com/Eka8veq.gif)

![Movimentando](https://i.imgur.com/Wat5jfH.gif)

**Como usar**

    CADA UM OBJETO É UM TIPO DE INTERAÇÃO PARA O USUÁRIO, CHECKBOX, TEXTEDIT, TRACKBAR, COMBOBOX E PROGRESSBAR;

Declaração dos objetos:
    NOME, **Func* & *Id**
    
   **NOME** é o unico **Obrigatorio** em todos.

|  Operating Systems  | Supported 32-bit | Supported 64-bit |
|:-------------------:|:----------------:|:----------------:|
| Windows 10          |         ✔        |         ✔       |



###### ex:
```Cpp
	checkbox checkbox1("caixa1");
	checkbox checkbox2("checked", true);
	TextEdit text1("Texto","Shadowy");
	TrackBar trackbar1("Num", 0, 10);
	ComboBox cb1("Textos");
```

Editar valor:
**      use a função .ChangeValue(int pos);

        Pos = Posição atual dos objetos:**
	
        - [x] Se a posição for igual o id.
	
        - [ ] Se a posição for diferente do id.
	
se a posição for igual o id do objeto ele é marcado assim como também é possivel alterar.
