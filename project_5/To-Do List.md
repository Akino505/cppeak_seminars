#### Управление задачами с приоритетами (To-Do List)

**Описание**: Система управления задачами с полями: ID, описание, приоритет (0–10), статус. Поддержка операций: добавить, выполнить (с учётом приоритета), отменить последнюю (через стек отмен).
**Контейнеры**:

- `std::priority_queue<std::tuple<int, int, std::string>>` — очередь по приоритету (приоритет, ID, описание)

- `std::stack<std::tuple<int, std::string, int>>` — стек для отмены (ID, описание, приоритет)

- `std::unordered_map<int, std::tuple<std::string, int, bool>>` — словарь задач (ID → описание, приоритет, статус)
    
    
    
    
    
    **Декомпозиция**:

```cpp
void addTask(std::unordered_map<...>& tasks, std::priority_queue<...>& pq, int id, const std::string& desc, int prio);
void completeTopTask(std::priority_queue<...>& pq, std::unordered_map<...>& tasks, std::stack<...>& undoStack);
void undoLast(std::stack<...>& undoStack, std::unordered_map<...>& tasks, std::priority_queue<...>& pq);
std::vector<std::tuple<int, std::string, int>> getPendingTasks(const std::unordered_map<...>& tasks);
```