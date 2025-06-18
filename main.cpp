#include "Tree.h"

int main() {
    DATA student;
    NODE* Tree1 = NULL;  
    NODE* Tree2 = NULL;  
    int choice;
    
    cout << "Структура даних: Студент (прізвище, рік народження, оцінка)" << endl << endl;
    
    while (true) {
        cout << "Бажаєте ввести дані про студента? (1 - так, 0 - ні): ";
        cin >> choice;
        if (!choice) break;
        
        cout << "Введіть прізвище студента: ";
        cin >> student.прізвище;
        cout << "Введіть рік народження: ";
        cin >> student.рікНародження;
        cout << "Введіть оцінку (0-100): ";
        cin >> student.оцінка;
        
        Add(student, Tree1);
        cout << "Студента додано до дерева!" << endl << endl;
    }
    
    if (!Tree1) {
        cout << "Дерево порожнє. Завершення програми." << endl;
        return 0;
    }
    
    cout << "\nДЕРЕВО, ОРГАНІЗОВАНЕ ЗА ПРІЗВИЩЕМ" << endl;
    cout << left << setw(15) << "Прізвище" << setw(10) << "Рік" << setw(8) << "Оцінка" << endl;
    cout << "---------------------------------------" << endl;
    ShowTree(Tree1);
    
    double avgGrade = AverageGrade(Tree1);
    int totalStudents = CountElements(Tree1);
    
    cout << "\nСТАТИСТИКА" << endl;
    cout << "Загальна кількість студентів: " << totalStudents << endl;
    cout << "Середня оцінка: " << fixed << setprecision(2) << avgGrade << endl;
    
    cout << "\nПЕРЕНЕСЕННЯ ДАНИХ У ДРУГЕ ДЕРЕВО" << endl;
    cout << "Переносимо дані з першого дерева у друге (організоване за роком народження)..." << endl;
    
    TransferToSecondTree(Tree1, Tree2);
    
    cout << "Видаляємо перше дерево з пам'яті" << endl;
    DeleteTree(Tree1);
    
    cout << "\nДРУГЕ ДЕРЕВО, ОРГАНІЗОВАНЕ ЗА РОКОМ НАРОДЖЕННЯ" << endl;
    cout << left << setw(15) << "Прізвище" << setw(10) << "Рік" << setw(8) << "Оцінка" << endl;
    cout << "---------------------------------------" << endl;
    ShowTree(Tree2);
    
    double avgGrade2 = AverageGrade(Tree2);
    int totalStudents2 = CountElements(Tree2);
    
    cout << "\nСТАТИСТИКА ДРУГОГО ДЕРЕВА" << endl;
    cout << "Загальна кількість студентів: " << totalStudents2 << endl;
    cout << "Середня оцінка: " << fixed << setprecision(2) << avgGrade2 << endl;
    
    cout << "\nВидаляємо друге дерево з пам'яті" << endl;
    DeleteTree(Tree2);
    
    cout << "Програма завершена успішно!" << endl;
    
    return 0;
}
