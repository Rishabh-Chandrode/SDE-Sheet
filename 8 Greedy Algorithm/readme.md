## 1)N meeting in one room
         Scheduling Events

            consider the following problem: Given n events with their starting
            and ending times, find a schedule that includes as many events as possible

            A third idea is to sort the events according to their ending times and always select
            the next possible event that ends as early as possible. It turns out that this algorithm
            always produces an optimal solution. To justify this, consider what happens if we
            first select an event that ends later than the event that ends as early as possible. Now,
            we will have at most an equal number of choices left how we can select the next
            event. Hence, selecting an event that ends later can never yield a better solution, and
            the greedy algorithm is correct.

## 2)Minimum Platform
        Sort both array
        Every entry in arr occupies one platform
        Every entry in dep releases one platform
