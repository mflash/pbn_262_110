public class Tipos
{
    public static void main(String[] args)
    {
        int a = 2147483647;
        System.out.println(a);
        a++;
        // Observe que o a++ não gera qualquer tipo de exceção!
        // Mas é um overflow, exatamente como ocorre em C!
        System.out.println(a);
    }
}
