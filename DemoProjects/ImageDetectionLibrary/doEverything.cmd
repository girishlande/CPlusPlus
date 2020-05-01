@echo off


call buildproject.cmd

call copydlls.cmd debug

call run.cmd

