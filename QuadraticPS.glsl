void main (void)
{
     //gradients
     vec4 px = dFdx(gl_FragCoord);
     vec4 py = dFdy(gl_FragCoord);
     
     //chain rule
     float fx = ((2 * gl_FragCoord.x) * px.x) - px.y;
     float fy = ((2 * gl_FragCoord.x) * py.x) - py.y;
     
     //signed distance
     float sd = ((gl_FragCoord.x * gl_FragCoord.x) - gl_FragCoord.y)/sqrt(fx*fx + fy*fy);

     //linear alpha
     float alpha = 0.5 - sd;
     
     if (alpha > 1)
     {
          alpha = 1;
     }
     else if (alpha < 0)
     {
          alpha = 0;
     }
     
     gl_FragColor = vec4(0.0, 1.0, 0.0, alpha);
}
