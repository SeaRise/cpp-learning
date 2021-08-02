- 异常处理
    - `#include <exception>`, `#include <stdexcept>`
    - try catch, 和java的处理差不多.
    ```
    try {
    
    } catch (const runtime_error &err) {
        // do something
    } catch (const exception &err) {
        // do something
    }
    ```