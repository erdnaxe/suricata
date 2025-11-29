pkglib_LTLIBRARIES = pcap-over-ip.la

pcap_over_ip_la_SOURCES = runmode-pcap-over-ip.c source-pcap-over-ip.c plugin.c
pcap_over_ip_la_LDFLAGS = -module -avoid-version -shared

noinst_HEADERS = \
	runmode-pcap-over-ip.h \
	source-pcap-over-ip.h

install-exec-hook:
	cd $(DESTDIR)$(pkglibdir) && $(RM) $(pkglib_LTLIBRARIES)
