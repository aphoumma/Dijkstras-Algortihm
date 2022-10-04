/*HANDOUT 1
Matrix for an input file

0 2 - 1 - 1 - 1 10
- 1 0 5 20 - 1 30
- 1 - 1 0 5 1 - 1
- 1 - 1 - 1 0 - 1 - 1
- 1 - 1 - 1 5 0 2
- 1 - 1 - 1 1 - 1 0
*/





#include<iostream>
#include<fstream>
using namespace std;

#define NUMBER_OF_NODES 6
#define INF 99999


struct Node
{

	int arrow[NUMBER_OF_NODES];

};

void initialize(int start, int* distance, int* predecessor, int* allowed, struct Node *node);
void one_round(int next, int* distance, int* predecessor, int* allowed, struct Node *node);
void graph_read(ifstream &instream, struct Node *node);

void travel(int next, int j, int* distance, int* predecessor, int* allowed, struct Node *node);

//int find_next(int* distance, int* allowed);
void print_arrays(int* distance, int* predecessor, int* allowed);

//void shortest_path(int start, int destination, int* predecessor);




int main()
{
	ifstream instream;


	Node node[NUMBER_OF_NODES];

	int i, j;

	int distance[NUMBER_OF_NODES];

	int allowed[NUMBER_OF_NODES];

	int predecessor[NUMBER_OF_NODES];

	int start, destination;

	int next;

	cout << "Please enter the start node" << endl;

	cin >> start;
	cout << "start is " << start << endl;

	cout << "Please enter the destination node" << endl;

	cin >> destination;




	initialize(start, distance, predecessor, allowed, node);

	print_arrays(distance, predecessor, allowed);
	instream.open("input.txt");

	graph_read(instream, node);

	next = start;

	one_round(next, distance, predecessor, allowed, node);

	print_arrays(distance, predecessor, allowed);





}




print_arrays(distance, predecessor, allowed);



return 0;
}

void initialize(int start, int* distance, int* predecessor, int* allowed, struct Node *node)
{
	int i;
	for (i = 0; i < NUMBER_OF_NODES; i++)

	{

		if (i == start)
		{
			distance[i] = 0;
			predecessor[i] = start ;
			allowed[i] = 1 ;


		}

		else
		{
			distance[i] = INF;
			predecessor[i] = -1 ;
			allowed[i] = 0 ;


		}
	}

}


void graph_read(ifstream  &instream, struct Node *node)
{
	int i, j;


	for (j = 0; j < NUMBER_OF_NODES; j++)
		for (i = 0; i < NUMBER_OF_NODES; i++)
			// read from file , put in node[j].arrow[i]
			instream >> node[j].arrow[i];

}

void print_arrays(int* distance, int* predecessor, int* allowed)
{

	int i;
	cout << "Printing distance, allowed and predecessor arrays" << endl;
	cout << "The distance array  is" << endl;

	for (i = 0; i < NUMBER_OF_NODES; i++)
		cout << distance[i] << "  ";
	cout << endl;

	cout << "The predecessor array  is" << endl;

	for (i = 0; i < NUMBER_OF_NODES; i++)
		cout << predecessor[i] << "  ";
	cout << endl;

	cout << "The allowed array  is" << endl;

	for (i = 0; i < NUMBER_OF_NODES; i++)
		cout << allowed[i] << "  ";
	cout << endl;
}

void travel(int next, int j, int* distance, int* predecessor, int* allowed, struct Node *node)

{

	int new_distance;

	new_distance = distance[? ] + ?


		if (new_distance < distance[j])
		{

			distance[j] = ? ;

			predecessor[j] = ? ;

		}
}


void one_round(int next, int* distance, int* predecessor, int* allowed, struct Node *node)
{

	int j;
	//allowed[next] = 1;
	for (j = 0; j < NUMBER_OF_NODES; j++)
		if (allowed[j] == 0 && node[next].arrow[j] != -1)
			travel(next, j, distance, predecessor, allowed, node);


}






