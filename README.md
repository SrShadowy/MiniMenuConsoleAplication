### MiniMenuConsoleAplication

[GitHub Sponsors](https://github.com/SrShadowy)


*Um menu em c++ sem muita pespectiva.
mas funcional*

**Como usar**

    CADA UM OBJETO É UM TIPO DE INTERAÇÃO PARA O USUÁRIO, CHECKBOX, TEXTEDIT, TRACKBAR, COMBOBOX E PROGRESSBAR;

Declaração dos objetos:
    NOME, **Func* & *Id**
    
   **NOME** é o unico **Obrigatorio** em todos.

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
