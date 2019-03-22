library(RColorBrewer)

FILES = list.files(path="RESULTS/HeatMaps", pattern="*.txt$")

for (i in 1:length(FILES)){
  
  dat <- read.csv(paste("RESULTS/HeatMaps/", FILES[i], sep=""), sep=" ")
  d_matrix <- log10(log10(as.matrix(dat) ) )
  
  coul <- colorRampPalette(c("white", "blue"),  interpolate = c("linear"))(50)

  jpeg(file=paste("FinalHeatMaps/", gsub(".txt",".jpg", FILES[i]), sep=""), width = 1920, height = 1080)
  heatmap(d_matrix, Rowv=NA, Colv= NA, scale="none", labRow=paste(""), labCol=paste(""), col=coul)#= heat.colors(1000)) #coul)
  dev.off()  
}    
      