from threading import Thread, Semaphore
import time 

sem = Semaphore(3)

def task(name):
    sem.acquire()
    for i in range(5):
        print("{} working".format(name))
        time.sleep(1)
    sem.release()
          
if __name__ == '__main__':
    t1 = Thread(target=task, args=('Thread-1',))
    t2 = Thread(target=task, args=('Thread-2',))
    t3 = Thread(target=task, args=('Thread-3',))
    t4 = Thread(target=task, args=('Thread-4',))
    
    t1.start()
    t2.start()
    t3.start()
    t4.start()

    # Wait for all threads to finish
    t1.join()
    t2.join()
    t3.join()
    t4.join()
