#include <stdio.h>

/**
 * print_chessboard - Prints the chessboard.
 * @board: The 2D array representing the chessboard.
 */
void print_chessboard(char (*board)[8])
{
	int row, col;

	for (row = 0; row < 8; row++)
	{
		for (col = 0; col < 8; col++)
		{
			putchar(board[row][col]);
		}
		putchar('\n');
	}
}
