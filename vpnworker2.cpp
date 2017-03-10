#include "vpnworker2.h"

extern "C"  {
#include "openfortivpn/src/config.h"
#include "openfortivpn/src/log.h"
#include "openfortivpn/src/tunnel.h"
}

vpnWorker2::vpnWorker2(QObject *parent) : QObject(parent)
{

}

void vpnWorker2::process()
{
    struct vpn_config cfg;
    memset(&cfg, 0, sizeof (cfg));
    strncpy(cfg.gateway_host, "***REMOVED***", FIELD_SIZE);
    cfg.gateway_host[FIELD_SIZE] = '\0';
    cfg.gateway_port = 10443;
    strncpy(cfg.username, "***REMOVED***", FIELD_SIZE);
    cfg.username[FIELD_SIZE] = '\0';
    strncpy(cfg.password, "***REMOVED***", FIELD_SIZE);
    cfg.password[FIELD_SIZE] = '\0';
    cfg.set_routes = 1;
    run_tunnel(&cfg);
}
