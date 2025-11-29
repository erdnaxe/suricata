# Pcap-over-IP Capture Plugin

## Building

To build this plugin, built Suricata with the `--enable-pcap-over-ip`.

## Running
```
/usr/local/suricata/bin/suricata \
    --set plugins.0=/usr/local/lib/suricata/pcap-over-ip.so \
    --capture-plugin=pcap-over-ip-plugin
```

### --set plugins.0=/usr/local/lib/suricata/pcap-over-ip.so

This command line option tells Suricata about this plugin. This could also
be done in `suricata.yaml` with the following section:
```
plugins:
  - /usr/local/lib/suricata/pcap-over-ip.so
```

### --capture-plugin=pcap-over-ip-plugin

This is the option that tells Suricata to use a plugin for capture, much like
`--pcap` tells Suricata to use libpcap or `--af-packet` tells Suricata to use
AF_PACKET. Here we are telling it to look for a loaded plugin of the name
`pcap-over-ip-plugin` to provide the capture method.

There is another command line option `--capture-plugin-args` to pass arbitrary
data on the command line a capture plugin, but this plugin does not yet handle
data provided through this command line parameter.
