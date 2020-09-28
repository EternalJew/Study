namespace lab2
{
    class Matrix
    {
        const int size = 3;
        public double[,] matrix = new double[size, size];
        public void Create()
        {
            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < size; j++)
                {
                    //Console.WriteLine("Введіть елемент [", i + 1 , ", ", j + 1, "]: ");
                    Console.WriteLine("Введiть елемент [{0}, {1}]:", i + 1, j + 1);

                    matrix[i, j] = double.Parse(Console.ReadLine());

                }
            }
            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < size; j++)
                {
                    Console.Write(string.Format("{0} ", matrix[i, j]));
                }
                Console.Write(Environment.NewLine + Environment.NewLine);
            }
            Console.ReadLine(); 

        }
        public void Solution()
        {
            double solution = 0;
            double solution1= 0;
            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < size; j++)
                {
                    //solution += matrix[i, i];
                    //solution += matrix[size - 1 - i, j];
                    if(i==j)
                    solution += matrix[i, j];
                    if (i + j == (size - 1)) solution1 += matrix[i, j];
                }
            }

           
            Console.WriteLine("Сума дiагоналей");
            Console.WriteLine(solution);
            Console.WriteLine(solution1);
        }
    }
    class Program
    {


        static void Main(string[] args)
        {
            Matrix matrix = new Matrix();
            matrix.Create();
            matrix.Solution();
            Console.ReadKey();
        }
    }
}
