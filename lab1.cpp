// lab1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _USE_MATH_DEFINES
#include <iostream>
#include <GLFW/glfw3.h>
#include <cmath>


float alpha = 0;
float getRand() {
    return (float)rand() / RAND_MAX * 2 - 1;
}
void showtriangle(int i) {
    glRotatef(alpha, 0.0f, 0.0f, 1.0f);
    glBegin(GL_TRIANGLES);
    glColor3f(0.7f, 1.0f, 0.0f);
    glVertex2f(-0.2f, 0.5f);
    //glColor3f(0.0f, 0.0f, 0.0f); 
    glVertex2f(0.0f, 0.0f);
    //glColor3f(0.0f, 0.4f, 0.6f); 
    glVertex2f(0.2f, 0.5f);
    glEnd();
    if (i % 2 == 0){
    glBegin(GL_TRIANGLE_STRIP);
    glColor3f(0.7f, 1.0f, 0.0f);
    glVertex2f(-0.1f, 0.65f);
   // glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.2f, 0.5f);
    //glColor3f(0.0f, 0.4f, 0.6f);
    glVertex2f(0.1f, 0.65f);
    //glColor3f(0.0f, 0.4f, 0.6f);
    glVertex2f(0.2f, 0.5f);
    glEnd();
    }
}


void shester(float alpha) {
    for (int i = 1; i < 17; i++) {
        glRotatef(22.5 * i, 0, 0, 1);
        showtriangle(i);
 
    }
    glRotatef(alpha, 0, 0, 1);
    float x, y;
    float cnt = 40;
    float l = 0.5, k = 0.4;
    float a = M_PI * 2 / cnt;
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 0.0f);
    for (int i = -1; i < cnt; i++)
    {
        x = sin(a * i) * l;
        y = cos(a * i) * l;
        glVertex2f(x, y);
    }
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1, 1, 1);

    for (int i = -1; i < cnt; i++)
    {
        x = sin(a * i) * k;
        y = cos(a * i) * k;
        glVertex2f(x, y);
    }
    glEnd();
}
int main(void)
{
    GLFWwindow* window;
    
    /* Initialize the library */
    if (!glfwInit())
        return -1;
    
    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 640, "MukhtarovTimerlan", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    srand(time(NULL));
    int mySeed = rand();
    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClearColor(0.7f, 1.0f, 0.7f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        srand(mySeed);
        
        for (int i = 1; i < 17; i++) {
            glPushMatrix();
            glLoadIdentity();
        
            glRotatef(22.5 * i, 0, 0, 1);
            showtriangle(i);
            glPopMatrix();
        }
        
        glPushMatrix();
        //glTranslatef(-0.7, -0.7, 0);
        //glScalef(0.5, 0.5, 1);
        glRotatef(alpha, 0, 0, 1);
        float x, y;
        float cnt = 40;
        float l = 0.6,k=0.4;
        float a = M_PI *2 / cnt;
        glBegin(GL_TRIANGLE_FAN);
        glColor3f(0.7f, 1.0f, 0.0f);
        
        for (int i = -1; i < cnt; i++)
        {
            x = sin(a * i) * l;
            y = cos(a * i) * l;
            glVertex2f(x, y);
        }
        glEnd();
        glBegin(GL_TRIANGLE_FAN);
        glColor3f(1, 1, 1);

        for (int i = -1; i < cnt; i++)
        {
            x = sin(a * i) * k;
            y = cos(a * i) * k;
            glVertex2f(x, y);
        }
        glEnd();
        glPopMatrix();
        /*for (int i = 0; i < 4; i++) {
            glLoadIdentity();
            glTranslatef(0.05*(i), 0.05 * (i), 0);
            glScalef(0.2 * (i+1), 0.2 * (i + 1), 0);
            shester(alpha);
        }*/
        

        /* Swap front and back buffers */
        glfwSwapBuffers(window);
        alpha += 0.05f;

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
