using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 冒泡排序CSharp
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] array = new int[1001];
            int num = Convert.ToInt32(Console.ReadLine());

            for (int i = 1; i <= num; i++)
            {
                array[i] = (Convert.ToInt32(Console.ReadLine()));
            }

            for (int i = 1; i <= num - 1; i++)
            {
                for (int j = 1; j <= num - i; j++)
                {
                    if (array[j] > array[j + 1])
                    {
                        int t = array[j];
                        array[j] = array[j + 1];
                        array[j + 1] = t;
                    }
                }
            }

            Console.WriteLine("===================");
            for (int i = 1; i <= num; i++)
            {
                Console.WriteLine(array[i]);
            }
        }
    }
}
