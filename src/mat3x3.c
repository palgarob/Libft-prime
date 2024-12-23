/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat3x3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 18:02:46 by pepaloma          #+#    #+#             */
/*   Updated: 2024/12/22 14:38:03 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <math.h>

t_vec3	mat3x3xvec3(t_mat3x3 mat, t_vec3 vec)
{
	return (vec_add(
			vec_scale_m(mat.i, vec.x),
			vec_add(
				vec_scale_m(mat.j, vec.y),
				vec_scale_m(mat.k, vec.z)
			)
	));
}

double	determinant(t_mat3x3 *mat)
{
	return (
		mat->i.x * (mat->j.y * mat->k.z - mat->j.z * mat->k.x)
		- mat->i.y * (mat->j.x * mat->k.z - mat->j.z * mat->k.x)
		+ mat->i.z * (mat->j.x * mat->k.y - mat->j.y * mat->k.x)
	);
}

int	mat_inverse(t_mat3x3 *mat, t_mat3x3 *inv)
{
	double		det;
	t_mat3x3	adj;

	det = determinant(mat);
	if (!det)
		return (0);
	adj.i.x = mat->j.y * mat->k.z - mat->j.z * mat->k.y;
	adj.i.y = -(mat->j.x * mat->k.z - mat->j.z * mat->k.x);
	adj.i.z = mat->j.x * mat->k.y - mat->j.y * mat->k.x;

	adj.j.x = -(mat->i.y * mat->k.z - mat->i.z * mat->k.y);
	adj.j.y = mat->i.x * mat->k.z - mat->i.z * mat->k.x;
	adj.j.z = -(mat->i.x * mat->k.y - mat->i.y * mat->k.x);

	adj.k.x = mat->i.y * mat->j.z - mat->i.z * mat->j.y;
	adj.k.y = -(mat->i.x * mat->j.z - mat->i.z * mat->j.x);
	adj.k.z = mat->i.x * mat->j.y - mat->i.y * mat->j.x;

	inv->i.x = adj.i.x / det;
	inv->i.y = adj.i.y / det;
	inv->i.z = adj.i.z / det;

	inv->j.x = adj.j.x / det;
	inv->j.y = adj.j.y / det;
	inv->j.z = adj.j.z / det;

	inv->k.x = adj.k.x / det;
	inv->k.y = adj.k.y / det;
	inv->k.z = adj.k.z / det;

	return (1);
}

void print_mat3x3(t_mat3x3 matrix)
{
	static int a = 1;
	if (a) {printf("[%.2f, %.2f, %.2f]\n", matrix.i.x, matrix.i.y, matrix.i.z);
	printf("[%.2f, %.2f, %.2f]\n", matrix.j.x, matrix.j.y, matrix.j.z);
	printf("[%.2f, %.2f, %.2f]\n", matrix.k.x, matrix.k.y, matrix.k.z);}
	a = 0;
}


t_mat3x3 multiply_mat3x3(t_mat3x3 a, t_mat3x3 b)
{
    t_mat3x3 result;

    // Row 1 of result
    result.i.x = a.i.x * b.i.x + a.i.y * b.j.x + a.i.z * b.k.x;
    result.i.y = a.i.x * b.i.y + a.i.y * b.j.y + a.i.z * b.k.y;
    result.i.z = a.i.x * b.i.z + a.i.y * b.j.z + a.i.z * b.k.z;

    // Row 2 of result
    result.j.x = a.j.x * b.i.x + a.j.y * b.j.x + a.j.z * b.k.x;
    result.j.y = a.j.x * b.i.y + a.j.y * b.j.y + a.j.z * b.k.y;
    result.j.z = a.j.x * b.i.z + a.j.y * b.j.z + a.j.z * b.k.z;

    // Row 3 of result
    result.k.x = a.k.x * b.i.x + a.k.y * b.j.x + a.k.z * b.k.x;
    result.k.y = a.k.x * b.i.y + a.k.y * b.j.y + a.k.z * b.k.y;
    result.k.z = a.k.x * b.i.z + a.k.y * b.j.z + a.k.z * b.k.z;

    return result;
}

int main()
{
	// Define a 3x3 matrix
	t_mat3x3 matrix = {
		.i = {9.0, 7.0, 3.0},
		.j = {4.3, 5.5, 6.0},
		.k = {0.8, 8.0, 4.3}
	};

	t_mat3x3 matrix2 = {
		.i = {7.0, 3.0, 2.7},
		.j = {3.0, 9.0, 0.0},
		.k = {2.0, 1.0, 1.0}
	};
	// Print the matrix
	printf("The 3x3 matrix is:\n");
//	print_mat3x3(matrix);
	t_mat3x3 matrix3 = multiply_mat3x3(matrix, matrix2);
	t_mat3x3	inv;
	mat_inverse(&matrix2, &inv);
	print_mat3x3(multiply_mat3x3(
		inv,
		matrix3
	));
	return 0;
}
