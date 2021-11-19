#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void* run_thread( void* id )
{
    int thread_id = *(int*)id;
    int count = 0;
    while ( count < 10 ) {
        sleep( 1 );
        printf( "Thread %d at count %d\n", thread_id, count++ );
    }

    pthread_exit( NULL );
    return 0;
}

int main( int argc, char* argv[] )
{
    sleep( 5 ); 
    int thread_count    = 0;
    while( thread_count < 10 ) {
        pthread_t my_thread;
        if ( pthread_create( &my_thread, NULL, run_thread, (void*)&thread_count ) < 0 )   {
            perror( "Error making thread...\n" );
            return 1;
        }

        pthread_detach( my_thread );
        thread_count++;
        sleep( 1 );
    }

    pthread_exit( 0 );  // added as per request
    return 0;
}
