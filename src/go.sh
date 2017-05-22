
# Pour monter le fichier grub : sudo mount -o loop,rw boot_fat_grub.img /mnt/tmp/
# Demonter : sudo umount /mnt/tmp
make
sudo rm /mnt/tmp/noyau/noyau.jlv
sync
sudo cp build/Debug/GNU-Linux/noyau.jlv /mnt/tmp/noyau/
sync
sudo bochs -qf bosh.bxrc