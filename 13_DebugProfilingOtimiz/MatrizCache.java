// Demonstrando que o acesso à memória sofre dos mesmos
// problemas em Java
public class MatrizCache
{
    public static void main(String[] args) {
        final int tam = 10000;
        double[][] mat = new double[tam][tam];

        for(int i=0; i<tam; i++)
            for(int j=0; j<tam; j++)
                mat[i][j] = 1.0;

        double soma = 0.0;

        long inicio = System.nanoTime();
        for(int i=0; i<tam; i++)
            for(int j=0; j<tam; j++)
                soma += mat[i][j];
        long fim = System.nanoTime();
        double dur = (fim-inicio) / 1e9; // converte para segundos
        System.out.println("Por linha: "+dur+" s");

        soma = 0.0;
        inicio = System.nanoTime();
        for(int j=0; j<tam; j++)
            for(int i=0; i<tam; i++)
                soma += mat[i][j];
        fim = System.nanoTime();
        dur = (fim-inicio) / 1e9; // converte para segundos
        System.out.println("Por coluna: "+dur+" s");
    }
}