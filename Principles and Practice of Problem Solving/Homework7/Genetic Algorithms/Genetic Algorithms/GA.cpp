#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <fstream>

using namespace std;

#define LEN 16
#define MINX -1
#define MAXX 15
#define POPSIZE 100		//[20, 200]
#define CROSSRATE 0.7	//[0.4, 0.99]
#define MUTARATE 0.007	//[0.005, 0.01]
#define GENS 500		//[100, 1000]


class individual
{
public:
	double x;
	double y;
	string dna;
	double fitness;

	string encode()
	{
		int fx = (int)(pow(2, x + 1) - 1); //[2^0-1, 2^16-1]
		//cout << "fx: " << fx << endl;
		string xdna;
		int re;
		while (fx >= 1)
		{
			re = fx % 2;
			switch (re)
			{
			case 0: xdna = "0" + xdna; break;
			case 1: xdna = "1" + xdna; break;
			}
			fx = fx / 2;
		}
		

		int l = xdna.size();
		while (l < LEN)
		{
			xdna = "0" + xdna;
			l++;
		}

		//cout << "decode: " << decode(xdna) << endl;

		return xdna;
	}


	double decode()
	{
		double fx = 1;
		for (int i = 0; i < LEN; i++)
		{
			fx = fx + (double)(dna[i] - '0') * pow(2, LEN - 1 - i);
		}
		double x = log(fx) / log(2) - 1;
		return x;
	}
	

	double f()
	{
		return x * sin(x);
	}

	double getfitness()
	{
		return y*(-1) + 15;
	}

	individual()
	{
		x = 0;
		y = 0;
		dna = "";
		fitness = -1;
	}

	individual(double val)
	{
		x = val;
		y = f();
		dna = encode();
		fitness = getfitness();
	}

	void change(int i)
	{
		if (dna[i] == '0')
		{
			dna[i] = '0';
		}
		else
		{
			dna[i] = '0';
		}
	}

	void renew()
	{
		//cout << dna << endl;
		x = decode();
		//cout << x << endl;
		y = f();
		fitness = getfitness();
	}
};

class GA
{
public:
	vector<individual> population;
	int x_pos;

	GA(int n)
	{
		x_pos = 0;
		double val;
		while (n--)
		{
			val = MINX + (double)(rand()) / RAND_MAX * (MAXX - MINX);	//[-1, 15]
			//cout << "val: " << val << endl;
			individual parent(val);
			population.push_back(parent);
			//cout << population[POPSIZE - n - 1].dna << endl;
			//system("pause");
		}
		//cout << population.size() << endl;
	}

	void crossover()
	{
		//cout << "crossover:" << endl;
		int n = POPSIZE / 2;
		double r;
		while (n--)
		{
			r = (double)(rand()) / RAND_MAX;
			//cout << "r = " << r << endl;
			if (r > CROSSRATE)
			{
				continue;
			}
			int singlepoint = rand() % 16;
			char tmp;
			/*
			cout << "before crossover" << endl;
			cout << population.size() << endl;
			cout << n << endl;
			cout << population[2 * n].dna << endl;
			cout << population[2 * n + 1].dna << endl;
			*/
			for (int i = 0; i <= singlepoint; i++)
			{
				tmp = population[2 * n].dna[i];
				population[2 * n].dna[i] = population[2 * n + 1].dna[i];
				population[2 * n + 1].dna[i] = tmp;
			}
			/*
			population[2 * n].renew();
			population[2 * n + 1].renew();
			cout << "after crossover" << endl;
			cout << population[2 * n].dna << endl;
			cout << population[2 * n + 1].dna << endl;
			system("pause");
			*/
		}
	}
	
	void mutation()
	{
		//cout << "mutation:" << endl;
		//cout << population.size() << endl;
		int n = POPSIZE;
		double r;
		while (n--)
		{
			for (int i = 0; i < LEN; i++)
			{
				r = (double)(rand()) / RAND_MAX;
				//cout << "r = " << r << endl;
				if (r > MUTARATE)
				{
					continue;
				}
				population[n].change(i);
			}
			population[n].renew();
		}
	}

	void selection()
	{
		//cout << "selection:" << endl;
		double totalfit = 0;
		vector<double> selectrate;	//每个个体被选择到下一代种群的概率
		vector<double> cumularate;	//每个个体被选择到下一代种群的概率区间

		for (int i = 0; i < POPSIZE; i++)
		{
			totalfit += population[i].fitness;
		}

		double relarate;
		double cumurate = 0;
		cumularate.push_back(cumurate);
		double maxrate = 0;
		for (int i = 0; i < POPSIZE; i++)
		{
			relarate = population[i].fitness / totalfit;
			//cout << "relarate[i]" << relarate << endl;
			selectrate.push_back(relarate);
			if (relarate > maxrate)
			{
				maxrate = relarate;
				x_pos = i;
			}
			cumurate += relarate;
			//cout << "cumurate["<<i<<"] "<< cumurate << endl;
			cumularate.push_back(cumurate);
		}
		//system("pause");

		//使用轮盘赌的方式进行选择相应数目的下一代
		double roulette; //模拟转盘指针
		vector<individual> offspring;
		int n = POPSIZE;
		while (n--)
		{
			roulette = (double)(rand()) / RAND_MAX;
			//cout << "rou=" << roulette << endl;
			//cout << "1:" << n << endl;
			for (int i = 0; i < POPSIZE; i++)
			{
				if (roulette == 0)
				{
					offspring.push_back(population[0]);
					break;
				}
				if (roulette == 1)
				{
					offspring.push_back(population[POPSIZE - 1]);
					break;
				}
				if (roulette > cumularate[i] && roulette <= cumularate[i + 1])
				{
					//cout << "i = " << i << " [" << cumularate[i] << "," << cumularate[i + 1] << "]" << endl;
					//cout << "2:" << n << endl;
					//cout << "offspring.add:" << population[i].dna << endl;
					offspring.push_back(population[i]);
					break;
				}
			}
			//system("pause");
		}
		//形成新一代
		population = offspring;
	}

	void reproduce()
	{
		fstream dataFile;
		dataFile.open("GA.txt", ios::out);
		int gen = 0;

		while (gen < GENS)
		{
			selection();	//选择
			crossover();	//交换
			mutation();		//变异
			gen++;
			dataFile << population[x_pos].fitness << endl;
			cout << "In " << gen << " generation: " << "x* = " << population[x_pos].x << " with fitness score " << population[x_pos].fitness << endl;
			//system("pause");
		}
	}
};


int main()
{
	srand(time(NULL));

	GA argminxsinx(POPSIZE);

	argminxsinx.reproduce();

	return 0;
}