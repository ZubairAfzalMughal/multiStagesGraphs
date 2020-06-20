using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Multi_Stages_Graphs
{
    class Program
    {
        static void Main(string[] args)
        {
            int[,] graphs =new int[9,9]{
		//   0,1,2,3,4,5,6,7,8
			{0,0,0,0,0,0,0,0,0}, //0
			{0,0,2,1,3,0,0,0,0}, //1
			{0,0,0,0,0,2,3,0,0}, //2
			{0,0,0,0,0,6,7,0,0}, //3
			{0,0,0,0,0,6,8,9,0}, //4
			{0,0,0,0,0,0,0,0,6}, //5
			{0,0,0,0,0,0,0,0,7}, //6
			{0,0,0,0,0,0,0,0,5}, //7
			{0,0,0,0,0,0,0,0,0}  //8
	        };
            // Display Graphs
            Console.Write("Multi Stage Graphs\n\n\n\n");
            for (int i = 0; i < 9; i++)
            {
                for (int j = 0; j < 9; j++)
                {
                    Console.Write(graphs[i, j] + "\t");
                }
                Console.WriteLine("\n");
            }
            int[] cost = new int[9]; //hold the cost of vertix
            int []d=new int[9]; // hold the destination of vertix
            int stages = 4;
            int[] path = new int[stages + 1];
            int n = 8;// last index
            int min;
            for(int i = n - 1; i >= 1; i--)
            {
                min = int.MaxValue;
                for(int j = i + 1; j <= n; j++)
                {
                    if(graphs[i,j]!=0 && (graphs[i, j] + cost[j]) < min)
                    {
                        min = graphs[i,j] + cost[j];
                        d[i] = j;
                    }
                    cost[i] = min;
                }
            }
            //Storing Optimal Solution
            path[0] = 0;
            path[1] = 1;
            path[stages] = n;
            for(int i = 2; i < stages; i++)
            {
                path[i] = d[path[i - 1]];
            }
            // Displaying the solution
            Console.Write("Optimal Solution\n\n\n");

            foreach(int i in path)
            {
                Console.Write(i + "\t");
            }
            Console.Read();
        }
    }
}
