#include "assignment-5_logMgr.h"
#include "stdlib.h"

/* Your log manager implementations here */
int add_to_log(log_manager* mgr, long timestamp) {
	enqueue(mgr->q, timestamp);
	while (timestamp > (mgr->q->head->data + mgr->window_duration)) {
		dequeue(mgr->q);
	}
	return mgr->q->size;
}

log_manager* createLogMgr(int delta) {
	log_manager* mgr = (log_manager *)malloc(sizeof(log_manager));
	mgr->q = initialize_q();
	mgr->window_duration = delta;
	return mgr;
}