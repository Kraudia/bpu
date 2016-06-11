import java.util.Random;

public class mnozenie {
    Integer[][] A, B, C;
    private int size;
	private Random rand = new Random();
    
    public mnozenie(int defaultSize) {
    	size = defaultSize;
    	A = new Integer[defaultSize][defaultSize];
    	B = new Integer[defaultSize][defaultSize];
    	C = new Integer[defaultSize][defaultSize];

        for (int i = 0; i < defaultSize; i++) {
            for (int j = 0; j < defaultSize; j++) {
            	A[i][j] = rand.nextInt(51);
            	B[i][j] = rand.nextInt(51);
                C[i][j] = 0;
            }
        }
    	
    }
    public Integer[][] matricesMultiply() {
        for (int i = 0; i < this.size; i++) { 
            for (int j = 0; j < this.size; j++) {
                for (int k = 0; k < this.size; k++) {
                    this.C[i][j] += this.A[i][k] * this.B[k][j];
                }
            }
        }

        return C;
    }

    public static void main(String[] args) {
    	int defaultSize = 500;
        mnozenie matrix = new mnozenie(defaultSize);
        
    	long startTime = System.currentTimeMillis();
        Integer[][] result = matrix.matricesMultiply();

/*        for (int i = 0; i < defaultSize; i++) {
            for (int j = 0; j < defaultSize; j++)
                System.out.print(result[i][j] + " ");
            
            System.out.println();
        }*/

        long endTime = System.currentTimeMillis();
        long executionTime = endTime - startTime;
        System.out.println("Execution time: " + executionTime/1000 + " seconds");
    }
}

