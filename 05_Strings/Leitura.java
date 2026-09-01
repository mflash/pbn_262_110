import java.util.Scanner;

public class Leitura
{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String pal = sc.next();
        System.out.println("Você digitou a palavra: "+pal);
        String linha = sc.nextLine(); // equivalente a fgets        
        System.out.println("Você digitou: "+linha);
    }
}