<!DOCTYPE html
	PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" lang="en-US" xml:lang="en-US">
<head>
<title>termios.cpp</title>
<link rel="stylesheet" type="text/css" href="/code/code.css" />
<meta http-equiv="Content-Type" content="text/html; charset=iso-8859-1" />
</head>
<body>
<div class="header">
<h1><a href="/code/.raw/termios.cpp">termios.cpp</a></h1>
(<a href="/code/.raw/termios.cpp">plain text</a>)
</div>
<table width="100%"><tr><td style="width: 1px;"><pre class="source lines"><a href="#l1" id="l1" name="l1">1</a>
<a href="#l2" id="l2" name="l2">2</a>
<a href="#l3" id="l3" name="l3">3</a>
<a href="#l4" id="l4" name="l4">4</a>
<a href="#l5" id="l5" name="l5">5</a>
<a href="#l6" id="l6" name="l6">6</a>
<a href="#l7" id="l7" name="l7">7</a>
<a href="#l8" id="l8" name="l8">8</a>
<a href="#l9" id="l9" name="l9">9</a>
<a href="#l10" id="l10" name="l10">10</a>
<a href="#l11" id="l11" name="l11">11</a>
<a href="#l12" id="l12" name="l12">12</a>
<a href="#l13" id="l13" name="l13">13</a>
<a href="#l14" id="l14" name="l14">14</a>
<a href="#l15" id="l15" name="l15">15</a>
<a href="#l16" id="l16" name="l16">16</a>
<a href="#l17" id="l17" name="l17">17</a>
<a href="#l18" id="l18" name="l18">18</a>
<a href="#l19" id="l19" name="l19">19</a>
<a href="#l20" id="l20" name="l20">20</a>
<a href="#l21" id="l21" name="l21">21</a>
<a href="#l22" id="l22" name="l22">22</a>
<a href="#l23" id="l23" name="l23">23</a>
<a href="#l24" id="l24" name="l24">24</a>
<a href="#l25" id="l25" name="l25">25</a>
<a href="#l26" id="l26" name="l26">26</a>
<a href="#l27" id="l27" name="l27">27</a>
<a href="#l28" id="l28" name="l28">28</a>
<a href="#l29" id="l29" name="l29">29</a>
<a href="#l30" id="l30" name="l30">30</a>
<a href="#l31" id="l31" name="l31">31</a>
<a href="#l32" id="l32" name="l32">32</a>
<a href="#l33" id="l33" name="l33">33</a>
<a href="#l34" id="l34" name="l34">34</a>
<a href="#l35" id="l35" name="l35">35</a>
<a href="#l36" id="l36" name="l36">36</a>
<a href="#l37" id="l37" name="l37">37</a>
<a href="#l38" id="l38" name="l38">38</a>
<a href="#l39" id="l39" name="l39">39</a>
<a href="#l40" id="l40" name="l40">40</a>
<a href="#l41" id="l41" name="l41">41</a>
<a href="#l42" id="l42" name="l42">42</a>
<a href="#l43" id="l43" name="l43">43</a>
<a href="#l44" id="l44" name="l44">44</a>
<a href="#l45" id="l45" name="l45">45</a>
<a href="#l46" id="l46" name="l46">46</a>
<a href="#l47" id="l47" name="l47">47</a>
<a href="#l48" id="l48" name="l48">48</a>
<a href="#l49" id="l49" name="l49">49</a>
<a href="#l50" id="l50" name="l50">50</a>
<a href="#l51" id="l51" name="l51">51</a>
<a href="#l52" id="l52" name="l52">52</a>
<a href="#l53" id="l53" name="l53">53</a>
<a href="#l54" id="l54" name="l54">54</a>
<a href="#l55" id="l55" name="l55">55</a>
<a href="#l56" id="l56" name="l56">56</a>
<a href="#l57" id="l57" name="l57">57</a>
<a href="#l58" id="l58" name="l58">58</a>
<a href="#l59" id="l59" name="l59">59</a>
<a href="#l60" id="l60" name="l60">60</a>
<a href="#l61" id="l61" name="l61">61</a>
<a href="#l62" id="l62" name="l62">62</a>
<a href="#l63" id="l63" name="l63">63</a>
<a href="#l64" id="l64" name="l64">64</a>
<a href="#l65" id="l65" name="l65">65</a>
<a href="#l66" id="l66" name="l66">66</a>
<a href="#l67" id="l67" name="l67">67</a>
<a href="#l68" id="l68" name="l68">68</a>
<a href="#l69" id="l69" name="l69">69</a>
<a href="#l70" id="l70" name="l70">70</a>
<a href="#l71" id="l71" name="l71">71</a>
<a href="#l72" id="l72" name="l72">72</a>
<a href="#l73" id="l73" name="l73">73</a>
<a href="#l74" id="l74" name="l74">74</a>
<a href="#l75" id="l75" name="l75">75</a>
<a href="#l76" id="l76" name="l76">76</a>
<a href="#l77" id="l77" name="l77">77</a>
<a href="#l78" id="l78" name="l78">78</a>
<a href="#l79" id="l79" name="l79">79</a>
<a href="#l80" id="l80" name="l80">80</a>
<a href="#l81" id="l81" name="l81">81</a>
<a href="#l82" id="l82" name="l82">82</a>
<a href="#l83" id="l83" name="l83">83</a>
<a href="#l84" id="l84" name="l84">84</a>
<a href="#l85" id="l85" name="l85">85</a>
<a href="#l86" id="l86" name="l86">86</a>
<a href="#l87" id="l87" name="l87">87</a>
<a href="#l88" id="l88" name="l88">88</a>
<a href="#l89" id="l89" name="l89">89</a>
<a href="#l90" id="l90" name="l90">90</a>
<a href="#l91" id="l91" name="l91">91</a>
<a href="#l92" id="l92" name="l92">92</a>
<a href="#l93" id="l93" name="l93">93</a>
<a href="#l94" id="l94" name="l94">94</a>
<a href="#l95" id="l95" name="l95">95</a>
<a href="#l96" id="l96" name="l96">96</a>
<a href="#l97" id="l97" name="l97">97</a>
<a href="#l98" id="l98" name="l98">98</a>
<a href="#l99" id="l99" name="l99">99</a>
<a href="#l100" id="l100" name="l100">100</a>
<a href="#l101" id="l101" name="l101">101</a>
<a href="#l102" id="l102" name="l102">102</a>
<a href="#l103" id="l103" name="l103">103</a>
<a href="#l104" id="l104" name="l104">104</a>
<a href="#l105" id="l105" name="l105">105</a>
<a href="#l106" id="l106" name="l106">106</a>
<a href="#l107" id="l107" name="l107">107</a>
<a href="#l108" id="l108" name="l108">108</a>
<a href="#l109" id="l109" name="l109">109</a>
<a href="#l110" id="l110" name="l110">110</a>
<a href="#l111" id="l111" name="l111">111</a>
<a href="#l112" id="l112" name="l112">112</a>
<a href="#l113" id="l113" name="l113">113</a>
<a href="#l114" id="l114" name="l114">114</a>
<a href="#l115" id="l115" name="l115">115</a>
<a href="#l116" id="l116" name="l116">116</a>
<a href="#l117" id="l117" name="l117">117</a>
<a href="#l118" id="l118" name="l118">118</a>
<a href="#l119" id="l119" name="l119">119</a>
<a href="#l120" id="l120" name="l120">120</a>
<a href="#l121" id="l121" name="l121">121</a>
<a href="#l122" id="l122" name="l122">122</a>
<a href="#l123" id="l123" name="l123">123</a>
<a href="#l124" id="l124" name="l124">124</a>
<a href="#l125" id="l125" name="l125">125</a>
<a href="#l126" id="l126" name="l126">126</a>
<a href="#l127" id="l127" name="l127">127</a>
<a href="#l128" id="l128" name="l128">128</a>
<a href="#l129" id="l129" name="l129">129</a>
<a href="#l130" id="l130" name="l130">130</a>
<a href="#l131" id="l131" name="l131">131</a>
<a href="#l132" id="l132" name="l132">132</a>
<a href="#l133" id="l133" name="l133">133</a>
<a href="#l134" id="l134" name="l134">134</a>
<a href="#l135" id="l135" name="l135">135</a>
<a href="#l136" id="l136" name="l136">136</a>
<a href="#l137" id="l137" name="l137">137</a>
<a href="#l138" id="l138" name="l138">138</a>
<a href="#l139" id="l139" name="l139">139</a>
<a href="#l140" id="l140" name="l140">140</a>
<a href="#l141" id="l141" name="l141">141</a>
<a href="#l142" id="l142" name="l142">142</a>
<a href="#l143" id="l143" name="l143">143</a>
<a href="#l144" id="l144" name="l144">144</a>
<a href="#l145" id="l145" name="l145">145</a>
<a href="#l146" id="l146" name="l146">146</a>
<a href="#l147" id="l147" name="l147">147</a>
<a href="#l148" id="l148" name="l148">148</a>
<a href="#l149" id="l149" name="l149">149</a>
<a href="#l150" id="l150" name="l150">150</a>
<a href="#l151" id="l151" name="l151">151</a>
<a href="#l152" id="l152" name="l152">152</a>
<a href="#l153" id="l153" name="l153">153</a>
<a href="#l154" id="l154" name="l154">154</a>
<a href="#l155" id="l155" name="l155">155</a>
<a href="#l156" id="l156" name="l156">156</a>
<a href="#l157" id="l157" name="l157">157</a>
<a href="#l158" id="l158" name="l158">158</a>
<a href="#l159" id="l159" name="l159">159</a>
<a href="#l160" id="l160" name="l160">160</a>
<a href="#l161" id="l161" name="l161">161</a>
<a href="#l162" id="l162" name="l162">162</a>
<a href="#l163" id="l163" name="l163">163</a>
<a href="#l164" id="l164" name="l164">164</a>
<a href="#l165" id="l165" name="l165">165</a>
<a href="#l166" id="l166" name="l166">166</a>
</pre></td><td><pre class="source"><span class="preproc">#<span class="id"><span class="keyword">include</span></span> <span class="string">&lt;iostream&gt;</span>
</span><span class="preproc">#<span class="id"><span class="keyword">include</span></span> <span class="string">&lt;string&gt;</span>
</span><span class="preproc">#<span class="id"><span class="keyword">include</span></span> <span class="string">&lt;cassert&gt;</span>
</span><span class="preproc">#<span class="id"><span class="keyword">include</span></span> <span class="string">&lt;climits&gt;</span>
</span><span class="preproc">#<span class="id"><span class="keyword">include</span></span> <span class="string">&lt;cstdio&gt;</span>
</span><span class="preproc">#<span class="id"><span class="keyword">include</span></span> <span class="string">&lt;cstring&gt;</span>
</span><span class="preproc">#<span class="id"><span class="keyword">include</span></span> <span class="string">&lt;termios.h&gt;</span>
</span><span class="preproc">#<span class="id"><span class="keyword">include</span></span> <span class="string">&lt;unistd.h&gt;</span>
</span>
<span class="keyword">class</span> <span class="id">Termios</span> <span class="braces">{</span>
 <span class="keyword">public</span><span class="symbol">:</span>
  <span class="keyword">explicit</span> <span class="id">Termios</span> <span class="symbol">(</span><span class="keyword">int</span> <span class="id">fd</span><span class="symbol">)</span>
    <span class="symbol">:</span> <span class="id">myFd</span><span class="symbol">(</span><span class="id">fd</span><span class="symbol">)</span> <span class="braces">{</span>
      <span class="id">assert</span><span class="symbol">(</span><span class="id">tcgetattr</span><span class="symbol">(</span><span class="id">myFd</span>, <span class="symbol">&amp;</span><span class="id">myStart</span><span class="symbol">)</span> <span class="symbol">=</span><span class="symbol">=</span> <span class="number">0</span><span class="symbol">)</span><span class="symbol">;</span>
      <span class="id">assert</span><span class="symbol">(</span><span class="id">tcgetattr</span><span class="symbol">(</span><span class="id">myFd</span>, <span class="symbol">&amp;</span><span class="id">myCurrent</span><span class="symbol">)</span> <span class="symbol">=</span><span class="symbol">=</span> <span class="number">0</span><span class="symbol">)</span><span class="symbol">;</span>
      <span class="id">reset</span><span class="symbol">(</span><span class="symbol">)</span><span class="symbol">;</span>
    <span class="braces">}</span>

  <span class="keyword">struct</span> <span class="id">input</span> <span class="braces">{</span>
    <span class="keyword">enum</span> <span class="braces">{</span>
      <span class="id">ignbrk</span> <span class="symbol">=</span> <span class="id">IGNBRK</span>,
      <span class="id">brkint</span> <span class="symbol">=</span> <span class="id">BRKINT</span>,
      <span class="id">ignpar</span> <span class="symbol">=</span> <span class="id">IGNPAR</span>,
      <span class="id">parmrk</span> <span class="symbol">=</span> <span class="id">PARMRK</span>,
      <span class="id">inpck</span> <span class="symbol">=</span> <span class="id">INPCK</span>,
      <span class="id">istrip</span> <span class="symbol">=</span> <span class="id">ISTRIP</span>,
      <span class="id">inlcr</span> <span class="symbol">=</span> <span class="id">INLCR</span>,
      <span class="id">igncr</span> <span class="symbol">=</span> <span class="id">IGNCR</span>,
      <span class="id">icrnl</span> <span class="symbol">=</span> <span class="id">ICRNL</span>,
      <span class="id">ixon</span> <span class="symbol">=</span> <span class="id">IXON</span>,
      <span class="id">ixoff</span> <span class="symbol">=</span> <span class="id">IXOFF</span>,
      <span class="id">ixany</span> <span class="symbol">=</span> <span class="id">IXANY</span>,
      <span class="id">imaxbel</span> <span class="symbol">=</span> <span class="id">IMAXBEL</span>,
    <span class="braces">}</span><span class="symbol">;</span>
  <span class="braces">}</span><span class="symbol">;</span>

  <span class="keyword">struct</span> <span class="id">output</span> <span class="braces">{</span>
    <span class="keyword">enum</span> <span class="braces">{</span>
      <span class="id">opost</span> <span class="symbol">=</span> <span class="id">OPOST</span>,
      <span class="id">onlcr</span> <span class="symbol">=</span> <span class="id">ONLCR</span>,
      <span class="id">ocrnl</span> <span class="symbol">=</span> <span class="id">OCRNL</span>,
      <span class="id">oxtabs</span> <span class="symbol">=</span> <span class="id">OXTABS</span>,
      <span class="id">onoeot</span> <span class="symbol">=</span> <span class="id">ONOEOT</span>,
      <span class="id">onocr</span> <span class="symbol">=</span> <span class="id">ONOCR</span>,
      <span class="id">onlret</span> <span class="symbol">=</span> <span class="id">ONLRET</span>,
    <span class="braces">}</span><span class="symbol">;</span>
  <span class="braces">}</span><span class="symbol">;</span>

  <span class="keyword">struct</span> <span class="id">control</span> <span class="braces">{</span>
    <span class="keyword">enum</span> <span class="braces">{</span>
      <span class="id">csize</span> <span class="symbol">=</span> <span class="id">CSIZE</span>,
      <span class="id">cs5</span> <span class="symbol">=</span> <span class="id">CS5</span>,
      <span class="id">cs6</span> <span class="symbol">=</span> <span class="id">CS6</span>,
      <span class="id">cs7</span> <span class="symbol">=</span> <span class="id">CS7</span>,
      <span class="id">cs8</span> <span class="symbol">=</span> <span class="id">CS8</span>,
      <span class="id">cstopb</span> <span class="symbol">=</span> <span class="id">CSTOPB</span>,
      <span class="id">cread</span> <span class="symbol">=</span> <span class="id">CREAD</span>,
      <span class="id">parenb</span> <span class="symbol">=</span> <span class="id">PARENB</span>,
      <span class="id">parodd</span> <span class="symbol">=</span> <span class="id">PARODD</span>,
      <span class="id">hupcl</span> <span class="symbol">=</span> <span class="id">HUPCL</span>,
      <span class="id">clocal</span> <span class="symbol">=</span> <span class="id">CLOCAL</span>,
      <span class="id">ccts_oflow</span> <span class="symbol">=</span> <span class="id">CCTS_OFLOW</span>,
      <span class="id">crtscts</span> <span class="symbol">=</span> <span class="id">CRTSCTS</span>,
      <span class="id">crts_iflow</span> <span class="symbol">=</span> <span class="id">CRTS_IFLOW</span>,
      <span class="id">mdmbuf</span> <span class="symbol">=</span> <span class="id">MDMBUF</span>,
    <span class="braces">}</span><span class="symbol">;</span>
  <span class="braces">}</span><span class="symbol">;</span>

  <span class="keyword">struct</span> <span class="id">local</span> <span class="braces">{</span>
    <span class="keyword">enum</span> <span class="braces">{</span>
      <span class="id">echoke</span> <span class="symbol">=</span> <span class="id">ECHOKE</span>,
      <span class="id">echoe</span> <span class="symbol">=</span> <span class="id">ECHOE</span>,
      <span class="id">echo</span> <span class="symbol">=</span> <span class="id">ECHO</span>,
      <span class="id">echonl</span> <span class="symbol">=</span> <span class="id">ECHONL</span>,
      <span class="id">echoprt</span> <span class="symbol">=</span> <span class="id">ECHOPRT</span>,
      <span class="id">echoctl</span> <span class="symbol">=</span> <span class="id">ECHOCTL</span>,
      <span class="id">isig</span> <span class="symbol">=</span> <span class="id">ISIG</span>,
      <span class="id">icanon</span> <span class="symbol">=</span> <span class="id">ICANON</span>,
      <span class="id">altwerase</span> <span class="symbol">=</span> <span class="id">ALTWERASE</span>,
      <span class="id">iexten</span> <span class="symbol">=</span> <span class="id">IEXTEN</span>,
      <span class="id">extproc</span> <span class="symbol">=</span> <span class="id">EXTPROC</span>,
      <span class="id">tostop</span> <span class="symbol">=</span> <span class="id">TOSTOP</span>,
      <span class="id">flusho</span> <span class="symbol">=</span> <span class="id">FLUSHO</span>,
      <span class="id">nokerninfo</span> <span class="symbol">=</span> <span class="id">NOKERNINFO</span>,
      <span class="id">pendin</span> <span class="symbol">=</span> <span class="id">PENDIN</span>,
      <span class="id">noflsh</span> <span class="symbol">=</span> <span class="id">NOFLSH</span>,
    <span class="braces">}</span><span class="symbol">;</span>
  <span class="braces">}</span><span class="symbol">;</span>

  <span class="id">tcflag_t</span> <span class="id">input_flags</span> <span class="symbol">(</span><span class="symbol">)</span> <span class="keyword">const</span> <span class="braces">{</span> <span class="keyword">return</span> <span class="id">myCurrent</span>.<span class="id">c_iflag</span><span class="symbol">;</span> <span class="braces">}</span>
  <span class="id">tcflag_t</span> <span class="id">output_flags</span> <span class="symbol">(</span><span class="symbol">)</span> <span class="keyword">const</span> <span class="braces">{</span> <span class="keyword">return</span> <span class="id">myCurrent</span>.<span class="id">c_oflag</span><span class="symbol">;</span> <span class="braces">}</span>
  <span class="id">tcflag_t</span> <span class="id">control_flags</span> <span class="symbol">(</span><span class="symbol">)</span> <span class="keyword">const</span> <span class="braces">{</span> <span class="keyword">return</span> <span class="id">myCurrent</span>.<span class="id">c_cflag</span><span class="symbol">;</span> <span class="braces">}</span>
  <span class="id">tcflag_t</span> <span class="id">local_flags</span> <span class="symbol">(</span><span class="symbol">)</span> <span class="keyword">const</span> <span class="braces">{</span> <span class="keyword">return</span> <span class="id">myCurrent</span>.<span class="id">c_lflag</span><span class="symbol">;</span> <span class="braces">}</span>
  <span class="keyword">const</span> <span class="id">cc_t</span> <span class="symbol">*</span><span class="id">control_chars</span> <span class="symbol">(</span><span class="symbol">)</span> <span class="keyword">const</span> <span class="braces">{</span> <span class="keyword">return</span> <span class="id">myCurrent</span>.<span class="id">c_cc</span><span class="symbol">;</span> <span class="braces">}</span>
  <span class="id">speed_t</span> <span class="id">input_speed</span> <span class="symbol">(</span><span class="symbol">)</span> <span class="keyword">const</span> <span class="braces">{</span> <span class="keyword">return</span> <span class="id">myCurrent</span>.<span class="id">c_ispeed</span><span class="symbol">;</span> <span class="braces">}</span>
  <span class="id">speed_t</span> <span class="id">output_speed</span> <span class="symbol">(</span><span class="symbol">)</span> <span class="keyword">const</span> <span class="braces">{</span> <span class="keyword">return</span> <span class="id">myCurrent</span>.<span class="id">c_ospeed</span><span class="symbol">;</span> <span class="braces">}</span>

  <span class="keyword">void</span> <span class="id">input_flags</span> <span class="symbol">(</span><span class="id">tcflag_t</span> <span class="id">flags</span><span class="symbol">)</span> <span class="braces">{</span> <span class="id">myCurrent</span>.<span class="id">c_iflag</span> <span class="symbol">=</span> <span class="id">flags</span><span class="symbol">;</span> <span class="braces">}</span>
  <span class="keyword">void</span> <span class="id">output_flags</span> <span class="symbol">(</span><span class="id">tcflag_t</span> <span class="id">flags</span><span class="symbol">)</span> <span class="braces">{</span> <span class="id">myCurrent</span>.<span class="id">c_oflag</span> <span class="symbol">=</span> <span class="id">flags</span><span class="symbol">;</span> <span class="braces">}</span>
  <span class="keyword">void</span> <span class="id">control_flags</span> <span class="symbol">(</span><span class="id">tcflag_t</span> <span class="id">flags</span><span class="symbol">)</span> <span class="braces">{</span> <span class="id">myCurrent</span>.<span class="id">c_cflag</span> <span class="symbol">=</span> <span class="id">flags</span><span class="symbol">;</span> <span class="braces">}</span>
  <span class="keyword">void</span> <span class="id">local_flags</span> <span class="symbol">(</span><span class="id">tcflag_t</span> <span class="id">flags</span><span class="symbol">)</span> <span class="braces">{</span> <span class="id">myCurrent</span>.<span class="id">c_lflag</span> <span class="symbol">=</span> <span class="id">flags</span><span class="symbol">;</span> <span class="braces">}</span>
  <span class="id">cc_t</span> <span class="symbol">*</span><span class="id">control_chars</span> <span class="symbol">(</span><span class="symbol">)</span> <span class="braces">{</span> <span class="keyword">return</span> <span class="id">myCurrent</span>.<span class="id">c_cc</span><span class="symbol">;</span> <span class="braces">}</span>
  <span class="keyword">void</span> <span class="id">input_speed</span> <span class="symbol">(</span><span class="id">speed_t</span> <span class="id">speed</span><span class="symbol">)</span> <span class="braces">{</span> <span class="id">myCurrent</span>.<span class="id">c_ispeed</span> <span class="symbol">=</span> <span class="id">speed</span><span class="symbol">;</span> <span class="braces">}</span>
  <span class="keyword">void</span> <span class="id">output_speed</span> <span class="symbol">(</span><span class="id">speed_t</span> <span class="id">speed</span><span class="symbol">)</span> <span class="braces">{</span> <span class="id">myCurrent</span>.<span class="id">c_ospeed</span> <span class="symbol">=</span> <span class="id">speed</span><span class="symbol">;</span> <span class="braces">}</span>

  <span class="comment">//! Apply my current settings to the stream.</span>
  <span class="keyword">void</span> <span class="id">apply</span> <span class="symbol">(</span><span class="symbol">)</span> <span class="braces">{</span> <span class="id">assert</span><span class="symbol">(</span><span class="id">tcsetattr</span><span class="symbol">(</span><span class="id">myFd</span>, <span class="id">TCSANOW</span>, <span class="symbol">&amp;</span><span class="id">myCurrent</span><span class="symbol">)</span> <span class="symbol">=</span><span class="symbol">=</span> <span class="number">0</span><span class="symbol">)</span><span class="symbol">;</span> <span class="braces">}</span>

  <span class="comment">//! Reset my current settings from the stream. </span>
  <span class="keyword">void</span> <span class="id">reset</span> <span class="symbol">(</span><span class="symbol">)</span> <span class="braces">{</span> <span class="id">assert</span><span class="symbol">(</span><span class="id">tcgetattr</span><span class="symbol">(</span><span class="id">myFd</span>, <span class="symbol">&amp;</span><span class="id">myCurrent</span><span class="symbol">)</span> <span class="symbol">=</span><span class="symbol">=</span> <span class="number">0</span><span class="symbol">)</span><span class="symbol">;</span> <span class="braces">}</span>

  <span class="comment">//! Restore the original stream settings.</span>
  ~<span class="id">Termios</span> <span class="symbol">(</span><span class="symbol">)</span> <span class="braces">{</span> <span class="id">assert</span><span class="symbol">(</span><span class="id">tcsetattr</span><span class="symbol">(</span><span class="id">myFd</span>, <span class="id">TCSANOW</span>, <span class="symbol">&amp;</span><span class="id">myStart</span><span class="symbol">)</span> <span class="symbol">=</span><span class="symbol">=</span> <span class="number">0</span><span class="symbol">)</span><span class="symbol">;</span> <span class="braces">}</span>

 <span class="keyword">private</span><span class="symbol">:</span>
  <span class="keyword">int</span> <span class="id">myFd</span><span class="symbol">;</span>
  <span class="keyword">struct</span> <span class="id">termios</span> <span class="id">myStart</span>, <span class="id">myCurrent</span><span class="symbol">;</span>
  <span class="keyword">explicit</span> <span class="id">Termios</span> <span class="symbol">(</span><span class="keyword">const</span> <span class="id">Termios</span> <span class="symbol">&amp;</span><span class="symbol">)</span><span class="symbol">;</span>
  <span class="id">Termios</span> <span class="symbol">&amp;</span><span class="keyword">operator</span><span class="symbol">=</span> <span class="symbol">(</span><span class="keyword">const</span> <span class="id">Termios</span> <span class="symbol">&amp;</span><span class="symbol">)</span><span class="symbol">;</span>
<span class="braces">}</span><span class="symbol">;</span>

<span class="comment">// char buffer which erases itself before deallocation</span>
<span class="keyword">template</span> <span class="symbol">&lt;</span><span class="id">size_t</span> <span class="id">N</span><span class="symbol">&gt;</span>
<span class="keyword">struct</span> <span class="id">ClassifiedBuffer</span> <span class="braces">{</span>
 <span class="keyword">public</span><span class="symbol">:</span>
  <span class="keyword">char</span> <span class="symbol">*</span><span class="id">buffer</span> <span class="symbol">(</span><span class="symbol">)</span> <span class="braces">{</span> <span class="keyword">return</span> <span class="id">myBuffer</span><span class="symbol">;</span> <span class="braces">}</span>
  <span class="keyword">const</span> <span class="keyword">char</span> <span class="symbol">*</span><span class="id">buffer</span> <span class="symbol">(</span><span class="symbol">)</span> <span class="keyword">const</span> <span class="braces">{</span> <span class="keyword">return</span> <span class="id">myBuffer</span><span class="symbol">;</span> <span class="braces">}</span>
  <span class="keyword">char</span> <span class="symbol">&amp;</span><span class="keyword">operator</span><span class="symbol">[</span><span class="symbol">]</span> <span class="symbol">(</span><span class="id">size_t</span> <span class="id">i</span><span class="symbol">)</span> <span class="braces">{</span> <span class="keyword">return</span> <span class="id">myBuffer</span><span class="symbol">[</span><span class="id">i</span><span class="symbol">]</span><span class="symbol">;</span> <span class="braces">}</span>
  <span class="keyword">const</span> <span class="keyword">char</span> <span class="symbol">&amp;</span><span class="keyword">operator</span><span class="symbol">[</span><span class="symbol">]</span> <span class="symbol">(</span><span class="id">size_t</span> <span class="id">i</span><span class="symbol">)</span> <span class="keyword">const</span> <span class="braces">{</span> <span class="keyword">return</span> <span class="id">myBuffer</span><span class="symbol">[</span><span class="id">i</span><span class="symbol">]</span><span class="symbol">;</span> <span class="braces">}</span>

  ~<span class="id">ClassifiedBuffer</span> <span class="symbol">(</span><span class="symbol">)</span> <span class="braces">{</span>
    <span class="id">std</span><span class="symbol">:</span><span class="symbol">:</span><span class="id">memset</span><span class="symbol">(</span><span class="id">myBuffer</span>, <span class="number">0</span>, <span class="id">N</span><span class="symbol">)</span><span class="symbol">;</span>

    <span class="comment">// to prevent the compiler from eliding the memset()</span>
    <span class="symbol">*</span><span class="id"><span class="keyword">const_cast</span></span><span class="symbol">&lt;</span><span class="keyword">volatile</span> <span class="keyword">char</span> <span class="symbol">*</span><span class="symbol">&gt;</span><span class="symbol">(</span><span class="id">myBuffer</span><span class="symbol">)</span> <span class="symbol">=</span> <span class="symbol">*</span><span class="id"><span class="keyword">const_cast</span></span><span class="symbol">&lt;</span><span class="keyword">volatile</span> <span class="keyword">char</span> <span class="symbol">*</span><span class="symbol">&gt;</span><span class="symbol">(</span><span class="id">myBuffer</span><span class="symbol">)</span><span class="symbol">;</span>
  <span class="braces">}</span>

 <span class="keyword">private</span><span class="symbol">:</span>
  <span class="keyword">char</span> <span class="id">myBuffer</span><span class="symbol">[</span><span class="id">N</span><span class="symbol">]</span><span class="symbol">;</span>
<span class="braces">}</span><span class="symbol">;</span>

<span class="id">std</span><span class="symbol">:</span><span class="symbol">:</span><span class="id">istream</span> <span class="symbol">&amp;</span><span class="id">noecho_getline</span> <span class="symbol">(</span><span class="keyword">char</span> <span class="symbol">*</span><span class="id">buf</span>, <span class="id">std</span><span class="symbol">:</span><span class="symbol">:</span><span class="id">size_t</span> <span class="id">len</span><span class="symbol">)</span> <span class="braces">{</span>
  <span class="id">Termios</span> <span class="id">termios</span><span class="symbol">(</span><span class="id">STDIN_FILENO</span><span class="symbol">)</span><span class="symbol">;</span>
  <span class="id">termios</span>.<span class="id">local_flags</span><span class="symbol">(</span><span class="id">termios</span>.<span class="id">local_flags</span><span class="symbol">(</span><span class="symbol">)</span> <span class="symbol">&amp;</span> ~<span class="symbol">(</span><span class="id">Termios</span><span class="symbol">:</span><span class="symbol">:</span><span class="id">local</span><span class="symbol">:</span><span class="symbol">:</span><span class="id">echo</span> <span class="symbol">|</span> <span class="id">Termios</span><span class="symbol">:</span><span class="symbol">:</span><span class="id">local</span><span class="symbol">:</span><span class="symbol">:</span><span class="id">icanon</span><span class="symbol">)</span><span class="symbol">)</span><span class="symbol">;</span>
  <span class="id">termios</span>.<span class="id">apply</span><span class="symbol">(</span><span class="symbol">)</span><span class="symbol">;</span>
  <span class="keyword">return</span> <span class="id">std</span><span class="symbol">:</span><span class="symbol">:</span><span class="id">cin</span>.<span class="id">getline</span><span class="symbol">(</span><span class="id">buf</span>, <span class="id">len</span><span class="symbol">)</span><span class="symbol">;</span>
<span class="braces">}</span>

<span class="keyword">int</span> <span class="id">main</span> <span class="symbol">(</span><span class="symbol">)</span> <span class="braces">{</span>
  <span class="id">setvbuf</span><span class="symbol">(</span><span class="id">stdin</span>, <span class="number">0</span>, <span class="id">_IONBF</span>, <span class="number">0</span><span class="symbol">)</span><span class="symbol">;</span> <span class="comment">// disable buffering in C library</span>

  <span class="comment">// disable buffering in C++ library</span>
<span class="preproc">#  <span class="keyword">if</span> <span class="id">defined</span><span class="symbol">(</span><span class="id">__GNUC__</span><span class="symbol">)</span> <span class="symbol">&amp;</span><span class="symbol">&amp;</span> <span class="id">__GNUC__</span> <span class="symbol">&lt;</span> <span class="number">3</span>
</span>  <span class="id">std</span><span class="symbol">:</span><span class="symbol">:</span><span class="id">cin</span>.<span class="id">rdbuf</span><span class="symbol">(</span><span class="symbol">)</span><span class="symbol">-</span><span class="symbol">&gt;</span><span class="id">setbuf</span><span class="symbol">(</span><span class="number">0</span>, <span class="number">0</span><span class="symbol">)</span><span class="symbol">;</span>
<span class="preproc">#  <span class="keyword">else</span>
</span>  <span class="id">std</span><span class="symbol">:</span><span class="symbol">:</span><span class="id">cin</span>.<span class="id">rdbuf</span><span class="symbol">(</span><span class="symbol">)</span><span class="symbol">-</span><span class="symbol">&gt;</span><span class="id">pubsetbuf</span><span class="symbol">(</span><span class="number">0</span>, <span class="number">0</span><span class="symbol">)</span><span class="symbol">;</span> 
<span class="preproc">#  <span class="id"><span class="keyword">endif</span></span>
</span>
  <span class="id">ClassifiedBuffer</span><span class="symbol">&lt;</span><span class="number">80</span><span class="symbol">&gt;</span> <span class="id">pwd</span><span class="symbol">;</span>

  <span class="keyword">if</span> <span class="symbol">(</span><span class="id">noecho_getline</span><span class="symbol">(</span><span class="id">pwd</span>.<span class="id">buffer</span><span class="symbol">(</span><span class="symbol">)</span>, <span class="number">80</span><span class="symbol">)</span><span class="symbol">)</span> <span class="braces">{</span>
    <span class="id">std</span><span class="symbol">:</span><span class="symbol">:</span><span class="id">cout</span>.<span class="id">put</span><span class="symbol">(</span><span class="char">'['</span><span class="symbol">)</span>.<span class="id">write</span><span class="symbol">(</span><span class="id">pwd</span>.<span class="id">buffer</span><span class="symbol">(</span><span class="symbol">)</span>, <span class="id">std</span><span class="symbol">:</span><span class="symbol">:</span><span class="id">strlen</span><span class="symbol">(</span><span class="id">pwd</span>.<span class="id">buffer</span><span class="symbol">(</span><span class="symbol">)</span><span class="symbol">)</span><span class="symbol">)</span>.<span class="id">put</span><span class="symbol">(</span><span class="char">']'</span><span class="symbol">)</span> <span class="symbol">&lt;</span><span class="symbol">&lt;</span> <span class="char">'<span class="esc">\n</span>'</span><span class="symbol">;</span>
  <span class="braces">}</span>

  <span class="keyword">return</span> <span class="number">0</span><span class="symbol">;</span>
<span class="braces">}</span>
</pre></td></tr></table>
</body>
</html>