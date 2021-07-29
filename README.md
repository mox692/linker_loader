# linker_loader
personal study of low level program through playing around with binary files and understanding the mechanism by which linkers work.
# environment
* [FreeBSD 12.2(amd64)](https://www.freebsd.org/releases/12.2R/announce/)
* [LLVM(llvm clang lld clang-extra libc++) 10.0.1](https://releases.llvm.org/)
# reference
* [リンカローダ実践開発テクニック](https://www.amazon.co.jp/%E3%83%AA%E3%83%B3%E3%82%AB%E3%83%BB%E3%83%AD%E3%83%BC%E3%83%80%E5%AE%9F%E8%B7%B5%E9%96%8B%E7%99%BA%E3%83%86%E3%82%AF%E3%83%8B%E3%83%83%E3%82%AF%E2%80%95%E5%AE%9F%E8%A1%8C%E3%83%95%E3%82%A1%E3%82%A4%E3%83%AB%E3%82%92%E4%BD%9C%E6%88%90%E3%81%99%E3%82%8B%E3%81%9F%E3%82%81%E3%81%AB%E5%BF%85%E9%A0%88%E3%81%AE%E6%8A%80%E8%A1%93-COMPUTER-TECHNOLOGY-%E5%9D%82%E4%BA%95-%E5%BC%98%E4%BA%AE/dp/4789838072)
* [Binary Hacks](https://www.amazon.co.jp/Binary-Hacks-%E2%80%95%E3%83%8F%E3%83%83%E3%82%AB%E3%83%BC%E7%A7%98%E4%BC%9D%E3%81%AE%E3%83%86%E3%82%AF%E3%83%8B%E3%83%83%E3%82%AF100%E9%81%B8-%E9%AB%98%E6%9E%97-%E5%93%B2/dp/4873112885/ref=pd_bxgy_img_2/355-2707981-5134624?pd_rd_w=kS4qr&pf_rd_p=d8f6e0ab-48ef-4eca-99d5-60d97e927468&pf_rd_r=1NNZAWZDZK9PKKHT5ZR7&pd_rd_r=dd8c1294-29be-42ba-8f54-e7da4c94ecce&pd_rd_wg=YvyWV&pd_rd_i=4873112885&psc=1)
