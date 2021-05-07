#include <bits/stdc++.h>
using namespace std;

void getTotalGQ(int numOfStudents, int gq[], int sum_gq[]);
void getTotalGPA(int numOfStudents, float gpa[], int sum_gpa[]);
void getTotalCount(int numOfStudents, int gq[], float gpa[], int count[][5]);

int main()
{
    int numOfStudents;
    cin >> numOfStudents;
    int *roll = new int[numOfStudents];
    int *gq = new int[numOfStudents];
    float *gpa = new float[numOfStudents];
}

void getTotalGQ(int numOfStudents, int gq[], int sum_gq[])
{
    int count;
    for (int i = 0; i < 10; ++i)
    {
        count = 0;
        for (int j = 0; j < numOfStudents; ++j)
        {
            if (gq[j] == i)
            {
                count += 1;
            }
        }
        sum_gq[i] = count;
    }
}

void getTotalGPA(int numOfStudents, float gpa[], int sum_gpa[])
{
    int count1, count2, count3, count4;
    // for (int i = 0; i < 10; ++i)
    // {
    count1 = 0;
    count2 = 0;
    count3 = 0;
    count4 = 0;
    for (int j = 0; j < numOfStudents; ++j)
    {
        if (gpa[j] == 0)
        {
            count1 += 1;
        }
        else if (gpa[j] == 0.3)
        {
            count2 += 1;
        }
        else if (gpa[j] == 0.6)
        {
            count3 += 1;
        }
        else if (gpa[j] == 1)
        {
            count4 += 1;
        }
    }
    sum_gpa[0] = count1;
    sum_gpa[1] = count2;
    sum_gpa[2] = count3;
    sum_gpa[3] = count4;
    // }
}

void getTotalCount(int numOfStudents, int gq[], float gpa[], int count[][5])
{
    for (int i = 0; i < 11; ++i)
    {
        for (int j = 0; i < 4; ++j)
        {
            count[i][j] = 0;
        }
    }
    for (int i = 0; i < numOfStudents; ++i)
    {
        if (gpa[i] == 0)
        {
            count[gq[i]][0] += 1;
        }
        else if (gpa[i] == 0.3)
        {
            count[gq[i]][1] += 1;
        }
        else if (gpa[i] == 0.6)
        {
            count[gq[i]][2] += 1;
        }
        else if (gpa[i] == 1)
        {
            count[gq[i]][3] += 1;
        }
    }
}