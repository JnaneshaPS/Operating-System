from threading import Thread, Lock
import time

lock = Lock()
count = 0

def task():
    global count
    lock.acquire()  # Acquire lock before the critical section
    try:
        for i in range(100000):
            count += 1
    finally:
      lock.release()  # Release lock after the critical section

if __name__ == '__main__':
    t1 = Thread(target=task)
    t2 = Thread(target=task)

    t1.start()
    t2.start()
    t1.join()
    t2.join()

    print(count)
