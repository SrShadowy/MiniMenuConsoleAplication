# MiniMenuConsoleAplication
Um menu em c++ sem muita pespectiva.
mas funcional

**Como usar**

    #Cada um objeto é um tipo de interação para o usuário, CheckBox, TextEdit, TrackBar, ComboBox e ProgressBar;

Declaração dos objetos:
    NOME, *FUNC* & *ID*
    Nome é o unico **Obrigatorio** em todos.

ex:
    checkbox checkbox1("caixa1");
	checkbox checkbox2("checked", true);
	TextEdit text1("Texto","Shadowy");
	TrackBar trackbar1("Num", 0, 10);
	ComboBox cb1("Textos");

Editar valor:
    use a função .ChangeValue(int pos);
    Pos = Posição atual dos objetos:
    - [x] Se a posição for igual o id.
    - [ ] Se a posição for diferente do id.
se a posição for igual o id do objeto ele é marcado assim como também é possivel alterar;

