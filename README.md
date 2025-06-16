# save_metrics_VK

## Методы: 

1) ### size_t GetCountTypes() const;
   Возвращает число добавленных имён метрик.

2) ### size_t GetAddedMetrics() const;
   Возвращает число изменений значений метрик.

3) ### bool AddNewType(std::string name);
   Добавляет новую метрику с названием name с нулевым значением.
   Возвращает true в случае успешнего добавления, иначе false.

4) ###  bool AddNewType(std::string name, double value);
    Добавляет новую метрику с названием name со значением value.
    Возвращает true в случае успешнего добавления, иначе false.

5) ### bool AddValue(std::string& name, double value);
   Переписывает в метрику с названием name значение value.
   Возвращает true в случае успешнего добавления, иначе false.

6)  ### double GetValue(std::string& name);
   Возвращает значение метрики с именем name.

7) ### bool IsMetric(std::string& name);
    Проверяет, есть ли метрика с именем name.

8) ### void Write(std::string filename);
    Записывает все метрики в файл с именем filename.
    Обнуляет все метрики.
