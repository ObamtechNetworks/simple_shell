#include "main.h"
/**
 * create_dir_node - creates a new directory node
 * @dir: the directory string to create node for
 * Return: returns pointer to the created directory node
 */
dir_node *create_dir_node(char *dir)
{
	/*create a new node and allocate space*/
	dir_node *new_node = NULL;
	new_node = malloc(sizeof(dir_node));
	if (new_node == NULL)
	{
		errno = ENOMEM;
		perror("mem allocation failed");
		exit(EXIT_FAILURE);
	}
	/*SET NEW NODE TO POINT TO DIRECTORY STRING*/
	new_node->dir = _strdup(dir);/**allocate memory for dir*/
	if (new_node->dir == NULL)
	{
		perror("strdup for dir failed");
		exit(EXIT_FAILURE);
	}
	/*set next of new node to point to NULL*/
	new_node->next = NULL;
	/*return the new node*/
	return (new_node);
}

/**
 * add_directory - adds a directory string to the linked list
 * @head: pointer to the head of the linked list
 * @dir: pointer to the directory string to add to the list
 * Return: nothing
 */
void add_directory(dir_node **head, char *dir)
{
	/*create a new node*/
	dir_node *new_dir = NULL;
	/*call the create directory node function with dir as arg*/
	new_dir = create_dir_node(dir);

	/*set next pointer of new_dir to head*/
	new_dir->next = *head;
	/*set head to point to new directory*/
	*head = new_dir;
}
/**
 * build_dir_list: this function builds a linked list of directories
 * Description: it parses the PATH variable environment into tokens
 * and then create a new head node
 * it then calls the add_directory() function which receives the head node
 * and then receives the address of head as first arugment
 * and then the parsed PATH tokens as directory string as second arg
 * Return: returns a pointer to the linked list of directories
 */
dir_node *build_dir_list(void)
{
	/*call getenv function to retrievd PATH string value*/
	char *path = _getenv("PATH");
	/*CREATE A STRUCT NODE AS *head*/
	dir_node *head = NULL;
	char *path_token = NULL;/*to receive the dir strs from strtok*/
	/*parse the path if valid*/
	if (path)
	{
		path_token = strtok(path, ":");
		/*loop through the path to get other fragments*/
		while (path_token != NULL)
		{
			/*call the add directory fxn and pass head as arg*/
			add_directory(&head, path_token);
			path_token = strtok(NULL, ":");
		}
		return (head);/*return the head of the list*/
	}
	return (NULL);
}
/**
 * free_dir_list: frees the directory nodes and entire linked list
 * @head: pointer to the head of the list
 * Return: nothing
 */
void free_dir_list(dir_node *head)
{
	/*create a temp node to iterate through the head*/
	dir_node *temp = NULL;
	/*loop through the head*/
	while (head != NULL)
	{
		/*set temp to be head*/
		temp = head;
		/*set head to point to next node*/
		head = head->next;
		/*free the nodes, both temp and head*/
		free(temp->dir);/*frees dir strings*/
		free(temp);/*frees the entir string*/
	}
}
